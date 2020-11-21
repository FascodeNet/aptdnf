#include "dnf_control.hpp"
int dnf_control::Install(std::vector<std::string> pkglist,PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("install");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    for(std::string i:pkglist){
        cmd_vector.push_back(i);
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
    //return 0;
}
int dnf_control::Remove(std::vector<std::string> pkglist,PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("remove");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    for(std::string i:pkglist){
        cmd_vector.push_back(i);
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
int dnf_control::Purge(std::vector<std::string> pkglist,PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("remove");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    for(std::string i:pkglist){
        cmd_vector.push_back(i);
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
int dnf_control::Upgrade(std::vector<std::string> pkglist,PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("update");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    for(std::string i:pkglist){
        cmd_vector.push_back(i);
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
int dnf_control::Search(std::vector<std::string> pkglist,PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("search");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    for(std::string i:pkglist){
        cmd_vector.push_back(i);
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
int dnf_control::Update(PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("update");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
int dnf_control::Full_Upgrade(PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("update");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
    return 0;
}
int dnf_control::Dist_Upgrade(PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("update");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
int dnf_control::Edit_sources(PmWrapper_pkgoptions optkun){
    FascodeUtil::msg msgkun=FascodeUtil::msg();
    msgkun.print(FascodeUtil::INFO,"aptdnf","Please edit /etc/yum.repos.d/ files");
    return 0;
}
int dnf_control::Autoremove(PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("autoremove");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
int dnf_control::List(PmWrapper_pkgoptions optkun){
    std::vector<std::string> cmd_vector;
    cmd_vector.push_back("dnf");
    cmd_vector.push_back("list");
    if(optkun.noconfirm){
        cmd_vector.push_back("-y");
    }
    return FascodeUtil::custom_exec_v(cmd_vector);
}
std::string dnf_control::get_core_info(){
    return "0.0.0.1";
}