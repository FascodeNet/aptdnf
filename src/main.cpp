#include "main.hpp"
int main(int argc,char* argv[]){
    FascodeUtil::msg msgkun=FascodeUtil::msg();
    PmWrapperInterface * pmwrapper=new dnf_control;
    PmWrapper_pkgoptions optkunniki;
    optkunniki.downloadonly=false;
    optkunniki.noconfirm=false;
    cmdline::parser p;
    p.set_program_name("aptdnf");
    p.add("version",'v',"show version");
    p.add("yes",'y',"no confirm");
    p.add("assume-yes",0,"no confirm");
    p.add("download-only",'d',"Only download the package.");
    p.add("purge",0,"Delete the entire configuration file.");
    p.add("help",'h',"show help");
    if (!p.parse(argc, argv)||p.exist("help")){
        std::cout<<p.error_full()<<p.usage();
        return 0;
    }
    if(p.exist("version")){
        msgkun.print(FascodeUtil::INFO,"aptdnf","Version : " + pmwrapper->get_core_info());
        return 0;
    }
    if(p.exist("yes")){
        optkunniki.noconfirm=true;
    }
    if(p.exist("assume-yes")){
        optkunniki.noconfirm=true;
    }
    if(p.exist("download-only")){
        optkunniki.downloadonly=true;
    }
    std::vector<std::string> opt_cmd_ls=p.rest();
    if(opt_cmd_ls.size() == 0){
        std::cout<<p.error_full()<<p.usage();
        return 0;
    }
    if(opt_cmd_ls.at(0) == "install") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        opt_cmd_ls.erase(opt_cmd_ls.begin());
        return pmwrapper->Install(opt_cmd_ls,optkunniki);
    }
    if(opt_cmd_ls.at(0) == "update") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        return pmwrapper->Update(optkunniki);
    }
    if(opt_cmd_ls.at(0) == "upgrade") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        opt_cmd_ls.erase(opt_cmd_ls.begin());
        return pmwrapper->Install(opt_cmd_ls,optkunniki);
    }
    if(opt_cmd_ls.at(0) == "remove") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        opt_cmd_ls.erase(opt_cmd_ls.begin());
        return pmwrapper->Remove(opt_cmd_ls,optkunniki);
    }
    if(opt_cmd_ls.at(0) == "purge") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        opt_cmd_ls.erase(opt_cmd_ls.begin());
        return pmwrapper->Purge(opt_cmd_ls,optkunniki);
    }
    if(opt_cmd_ls.at(0) == "search") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        opt_cmd_ls.erase(opt_cmd_ls.begin());
        return pmwrapper->Search(opt_cmd_ls,optkunniki);
    }
    if(opt_cmd_ls.at(0) == "full-upgrade") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        return pmwrapper->Full_Upgrade(optkunniki);
    }
    if(opt_cmd_ls.at(0) == "dist-upgrade") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        return pmwrapper->Dist_Upgrade(optkunniki);
    }

    if(opt_cmd_ls.at(0) == "edit-sources") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        return pmwrapper->Edit_sources(optkunniki);
    }
    if(opt_cmd_ls.at(0) == "autoremove") {
        msgkun.print(FascodeUtil::DEBUG,"aptdnf",opt_cmd_ls.at(0));
        return pmwrapper->Autoremove(optkunniki);
    }



    return 0;
}