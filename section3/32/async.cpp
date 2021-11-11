#include <future>
#include <string>

int age_universe()
{
    return 5000;
}

std::string helloFunction(const std::string& s){
  return "Hello C++11 from " + s + ".\n";
}

int main()
{
    std::future<std::string> name = std::async(helloFunction, "Kenneth");
    printf("%s", name.get().c_str());
    
    return 0;
}