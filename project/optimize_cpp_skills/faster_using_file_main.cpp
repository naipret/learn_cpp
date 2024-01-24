#include <fstream>
#include <ios>

// using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    constexpr std::streamsize buffer_size{4096};
    char buffer[buffer_size];

    

    std::ifstream input{};
    input.rdbuf()->pubsetbuf(buffer, buffer_size);
    input.open("", std::ios::binary);
    
    input.close();

    

    std::ofstream output{};
    output.rdbuf()->pubsetbuf(buffer, buffer_size);
    output.open("", std::ios::binary);
    
    output.close();

    return 0;
}
