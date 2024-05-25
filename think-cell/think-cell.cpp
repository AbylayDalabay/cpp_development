#include <iostream>
#include <map>
template<typename K, typename V>
class interval_map {
    friend void IntervalMapTest();
    V m_valBegin;
    std::map<K,V> m_map;
public:
    // constructor associates whole range of K with val
    interval_map(V const& val)
    : m_valBegin(val)
    {}

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the int
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val){
        
    }
    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        auto it=m_map.upper_bound(key);
        if(it==m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    }
};

std::map<int, char> M;

void print(std::map<int, char>::iterator const& keyBegin, std::map<int, char>::iterator const& keyEnd){
    for(auto it = keyBegin;it != keyEnd;it++){
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }
}

int main(){
    for(int i = 0;i < 20;i++){
        M.insert({i, static_cast<char>('a' + i)});
    }

    //print(M.begin(), M.end());

    auto lb = M.lower_bound(5);
    print(lb, std::next(lb));

    auto ub = M.upper_bound(10);
    print(ub, std::next(ub));

    std::cout << "________________________" <<  std::endl;

    M.erase(lb, ub);
    print(M.begin(), M.end());

    std::cout << "________________________" <<  std::endl;

    print(ub, std::next(ub));
}