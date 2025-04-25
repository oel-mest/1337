#include "SedReplace.hpp"

SedReplace::SedReplace(std::string fn, std::string bs, std::string ns):
    filename(fn), baseString(bs), newString(ns) {}

SedReplace::~SedReplace(void)
{
    closeFiles();
}

void SedReplace::setNewName(void)
{
    newName = filename + ".replace";
}

bool SedReplace::checkFolder(void)
{
    struct stat	type;

    if (stat(filename.c_str(), &type) == 0 && type.st_mode & S_IFDIR) {
		std::cerr << "'" << filename << "': is a directory" << std::endl;
		return (true);
	}
    if (stat(newName.c_str(), &type) == 0 && type.st_mode & S_IFDIR) {
		std::cerr << "'" << newName << "': exist and its a directory" << std::endl;
		return (true);
	}
    return (false);
}

bool SedReplace::setFileIn(void)
{
    fileIn.open(filename.c_str(), std::ifstream::in);
    if (fileIn.good() && fileIn.is_open())
        return true;
    std::cerr << "Error opening " << filename << std::endl;
    closeFiles();
    return false;
}

bool SedReplace::setFileOut(void)
{
    fileOut.open(newName.c_str(), std::ifstream::out);
    if (fileOut.good() && fileOut.is_open())
        return true;
    std::cerr << "Error opening " << newName << std::endl;
    closeFiles();
    return false;
}

void    SedReplace::closeFiles(void)
{
    fileIn.close();
    fileOut.close();
}

bool    SedReplace::replace(void)
{
    char c;

    if (this->setFileIn() && this->setFileOut())
    {
        while (!fileIn.eof() && fileIn >> std::noskipws >> c)
        {
            content += c;
        }
        for (int i = 0; i < (int)content.length(); i++)
        {
            int pos = content.find(baseString, i);
            if (pos == i && baseString.length() > 0)
            {
                fileOut << newString;
                i += baseString.length() - 1;
            }
            else
            {
                fileOut << content[i];
            }
        }
    }
    else
        return (false);
    return true;
}