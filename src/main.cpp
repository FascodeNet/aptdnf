#include "main.hpp"
using namespace nonsugar;
int main(int argc,char* argv[]){
    FascodeUtil::msg msgkun=FascodeUtil::msg();
    try{
        auto const cmd = command<char>("aptdnf","aptdnf")
        .flag<'h'>({},{"help"},"","help");
        auto const opts=parse(argc,argv,cmd);
        if(opts.has<'h'>()){
            std::cout << usage(cmd);
            return 0;
        }
    } catch (error const &e) {
        msgkun.print(FascodeUtil::ERR,"aptdnf",e.message());
        return 1;
    }

    return 0;
}