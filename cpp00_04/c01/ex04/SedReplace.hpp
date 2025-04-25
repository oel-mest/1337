#ifndef SEDREPLACE_HPP
#define SEDREPLACE_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

class SedReplace {
    private:
        std::string filename;
        std::string baseString;
        std::string newString;
        std::string newName;
        std::string content;

        std::ifstream fileIn;
        std::ofstream fileOut;
    public:
        SedReplace(std::string fn, std::string bs, std::string ns);
        SedReplace(void);
        ~SedReplace(void);
        void    setNewName(void);
        bool    setFileIn(void);
        bool    setFileOut(void);
        bool    replace(void);
        void    closeFiles(void);
        bool    checkFolder(void);
};

#endif // SEDREPLACE_HPP