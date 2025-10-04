#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>


int main()
{

    int constexpr threshold = 1000;
    std::vector<int> v1 ={1,2,3,4,5,6,7,8,9};
    std::vector<int> v2 ={1,5,6,8,9,10,11,12};
    
    bool value = std::all_of(v1.begin(),v1.end(),[](int i){return i > 0;});
    std::cout << value << std::endl;
    value = std::any_of(v1.begin(),v1.end(),[](int i){return i > 5;});
    std::cout << value << std::endl;
    value = std::none_of(v1.begin(),v1.end(),[](int i){return i > 100;});
    std::cout << value << std::endl;

    std::for_each(v1.begin(),v1.end(),[threshold](int& i){i=i*2 + threshold ;});
    //std::cout << *(static_cast<int*>(v1.data()));
    for(auto i :v1)
    {
        std::cout << i << std::endl;
    }
    std::for_each_n(v2.begin(),5,[threshold](int& i){i=i*2 + threshold ;});
    for(auto i :v2)
    {
        std::cout << i << std::endl;
    }
    std::vector<std::string> names ={"Mahmoud","Yasmin","Omar","Karim","Omar","Mohamed"};
    std::cout << std::count(names.begin(),names.end(),"Omar") << std::endl;
    std::cout << std::count_if(names.begin(),names.end(),[](std::string &n){return n=="Omar";})<<std::endl;
    
    std::vector<int> v3 = {1,2,3,4,5,6};
    std::vector<int> v4 = {1,2,3,8,5,9};
    auto p = std::mismatch(v3.begin(),v3.end(),v4.begin());
    std::cout << *(p.first) << " " << *(p.second) << std::endl;

    auto found = std::find(v3.begin(),v3.end(),100);
    if (found != v3.end())
    {
        std::cout << "Found" << std::endl;
    }
    std::vector<int> result(v3.size());
    
    for(auto i :v3)
    {
        std::cout << i << std::endl;
    }
    std::copy_if(v3.begin(),v3.end(),result.begin(),[](int i){return i % 2 == 0;});
    for(auto i :result)
    {
        std::cout << i << std::endl;
    }
    std::vector<int> v5(result.size());
    std::move(result.begin(),result.end(),v5.begin());
    for(auto i :result)
    {
        std::cout << i << std::endl;
    }
    int val= 5;
    std::vector<int> u = {100,200,300,400,500,600};
    std::generate(u.begin(),u.end(),[&val](){return val++;});

    
}
