#pragma once
#include "pm-wrapper-interface.hpp"
#include "custom_exec.hpp"
#include "message.hpp"
class dnf_control:public PmWrapperInterface{
    int Install(std::vector<std::string>,PmWrapper_pkgoptions);
    int Remove(std::vector<std::string>,PmWrapper_pkgoptions);
    int Purge(std::vector<std::string>,PmWrapper_pkgoptions);
    int Update(PmWrapper_pkgoptions);
    int Upgrade(std::vector<std::string>,PmWrapper_pkgoptions);
    int Search(std::vector<std::string>,PmWrapper_pkgoptions);
    int Full_Upgrade(PmWrapper_pkgoptions);
    int Edit_sources(PmWrapper_pkgoptions);
    int Dist_Upgrade(PmWrapper_pkgoptions);
    int Autoremove(PmWrapper_pkgoptions);
    int List(PmWrapper_pkgoptions);
    std::string get_core_info();
};