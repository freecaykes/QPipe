#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <tuple>
#include <list>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

#include <sys/stat.h>
#include <unistd.h>

using namespace std;

class XMLWriter
{
public:
    string log_title_date;
    XMLWriter();
    XMLWriter(string filename);
    ~XMLWriter(){fclose(this->log_stream);}

    typedef struct {
        int parents;
        string title;
        string value;
        list<string> attributes;
        list<string> attribute_values; // 1-1 mapping from attributes to attribute_values
    }XMLENTRY;

    FILE* getLogStream();

    XMLENTRY xmlEntry_create(string title, string value, int parents, list<std::string> attributes, list<std::string> attribute_values);
    tuple<string,string> xmlEntry_toString(XMLENTRY* entry, int parents);

    void log(XMLENTRY entry, bool close);  // write to file
    void log_closeTag(int parents, string title);

private:
    FILE* log_stream;

    bool createNewLogFile();
    bool fileExists (string name);

    bool callback;
    const string XML_HEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
};

#endif // XMLWRITER_H
