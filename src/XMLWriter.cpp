#include "XMLWriter.h"

#define ENCODING ""

using namespace std;

XMLWriter::XMLWriter(string filename)
{
    string LOGS = "./logs/";
    if(!this->fileExists(LOGS))
    {
        string cmd = "mkdir " + LOGS;
        system(cmd.c_str());
    }

    log_title_date =  LOGS + filename + ".xml";

    // create empty xml file
    if (!this->fileExists(log_title_date))
    {
        //open new file
        log_stream = fopen(log_title_date.c_str(), "a+");
        fputs(XML_HEADER.c_str(), log_stream);
    }else
    {
        // re-open if already exists
        log_stream = fopen(log_title_date.c_str(), "a+");
    }
}

bool XMLWriter::fileExists (string name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}

FILE* XMLWriter::getLogStream()
{
    return log_stream;
}


void XMLWriter::log(XMLENTRY entry, bool close)
{
    if (log_stream)
    {
        string header_body_tag; string close_tag;
        std::tie (header_body_tag, close_tag) = this->xmlEntry_toString(&entry, entry.parents);
        string xml_entry;

        if (close)
        {
            xml_entry = header_body_tag + close_tag + "\n";
        }else
        {
            xml_entry = header_body_tag + "\n";
        }
        fputs(xml_entry.c_str(), log_stream);
    }else
    {
        // Sys failure: Filte DNE
        std::cerr << "Failed to find log file: " << log_title_date;
        return;
    }
}

void XMLWriter::log_closeTag(int parents, string title)
{
    if(log_stream)
    {
        string tabs = "";
        for (int i=0; i < parents; i++)
        {
            tabs += "    ";
        }
        string close_tag = tabs + "</" + title + ">\n";
        fprintf(log_stream, close_tag.c_str());
    }
    else{
      std::cerr << "Failed to find log file: " << log_title_date;
    }
}


XMLWriter::XMLENTRY XMLWriter::xmlEntry_create(string title, string value, int parents, list<std::string> attributes, list<std::string> attribute_values)
{
    XMLENTRY xml_entry;

    xml_entry.value = value;
    xml_entry.title = title;
    xml_entry.parents = parents;
    xml_entry.attributes = attributes;
    xml_entry.attribute_values = attribute_values;

    return xml_entry;
}

tuple<string, string> XMLWriter::xmlEntry_toString(XMLENTRY* entry, int parents)
{
    string xml_entry = "<"+entry->title;
    string tabs = "";
    for (int p=0; p < parents; p++)
    {
        tabs += "    ";
    }
    xml_entry = tabs + xml_entry;

    list<string> attributes = entry->attributes;
    list<string> attribute_values = entry->attribute_values;
    if(attributes.size() > 0)
    {
        int att_size = attributes.size();
        for (int i=0; i< att_size; i++)
        {
            string attr_val_pair = " " + attributes.front() + "=\"" + attribute_values.front() + "\"";
            attributes.pop_front();
            attribute_values.pop_front();
            xml_entry = xml_entry + attr_val_pair;
        }
    }
    xml_entry = xml_entry + ">";

    // append value if there is one
    if(entry->value.length() > 0)
    {
        xml_entry = xml_entry + entry->value;
    }

    string xml_close_tag = "</" + entry->title + ">";
    return std::make_tuple (xml_entry, xml_close_tag);
}
