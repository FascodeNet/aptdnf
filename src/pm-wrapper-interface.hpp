#pragma once
#include <string>
#include <vector>
struct PmWrapper_pkgoptions{
    bool noconfirm;
    bool downloadonly;
};
class PmWrapperInterface{
    public:
        virtual ~PmWrapperInterface() {};
        virtual int Install(std::vector<std::string>,PmWrapper_pkgoptions)=0;
        virtual int Remove(std::vector<std::string>,PmWrapper_pkgoptions)=0;
        virtual int Purge(std::vector<std::string>,PmWrapper_pkgoptions)=0;
        virtual int Update(PmWrapper_pkgoptions)=0;
        virtual int Upgrade(std::vector<std::string>,PmWrapper_pkgoptions)=0;
        virtual int Search(std::vector<std::string>,PmWrapper_pkgoptions)=0;
        virtual int Full_Upgrade(PmWrapper_pkgoptions)=0;
        virtual int Edit_sources(PmWrapper_pkgoptions)=0;
        virtual int Dist_Upgrade(PmWrapper_pkgoptions)=0;
        virtual int Autoremove(PmWrapper_pkgoptions)=0;
        virtual int List(PmWrapper_pkgoptions)=0;
        virtual std::string get_core_info()=0;

};