#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

namespace {
    struct GroupAdminInfo {
        std::string groupName;
        std::string groupAdminUserID;
        std::string groupAdminUserName;
        std::string groupAdminEmailId;
    };
}

int getGroupAdminInfo(const std::string& groupName, GroupAdminInfo* info );

int main()
{
    GroupAdminInfo info;
    return getGroupAdminInfo("sc-004", &info);
}

int getGroupAdminInfo( const std::string& groupName, GroupAdminInfo* info )
{
    const char* FILE_LOCATION = "D:\\Temp\\groupadmininfo.csv";
    const char* DELIMITER = ",";

    // Create a text string, which is used to output the text file
    std::string line;

    // Read from the text file
    std::ifstream fGroupAdminFile(FILE_LOCATION);

    // Use a while loop together with the getline() function to read the file line by line
    while (std::getline(fGroupAdminFile, line))
    {
        int delimiterPos = line.find(DELIMITER);
        std::string groupNameFromFile = line.substr(0, delimiterPos);
        if (groupName == groupNameFromFile)
        {
            // line is now sc-001,pdittaka,pavan dittakavi,pavan.dittakavi@asml.com
            info->groupName = groupName; // sc-001

            line = line.substr(line.find(DELIMITER) + 1); // line is now pdittaka,pavan dittakavi,pavan.dittakavi@asml.com
            info->groupAdminUserID = line.substr(0, line.find(DELIMITER));

            line = line.substr(line.find(DELIMITER) + 1); // line is now pavan dittakavi,pavan.dittakavi@asml.com
            info->groupAdminUserName = line.substr(0, line.find(DELIMITER));

            line = line.substr(line.find(DELIMITER) + 1); // line is now pavan.dittakavi@asml.com
            info->groupAdminEmailId = line;

            break;
        }
    }

    // Close the file
    fGroupAdminFile.close();
    return 0;
}
