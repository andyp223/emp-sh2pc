#include "emp-sh2pc/emp-sh2pc.h"
using namespace emp;
using namespace std;
const string circuit_file_location = macro_xstr(EMP_CIRCUIT_PATH);

int port, party;
string file = circuit_file_location+"/AES-non-expanded.txt";//adder_32bit.txt";
CircuitFile cf(file.c_str());

void test() {
	auto start = clock_start();
	Integer a(128, 2, ALICE);
	Integer b(128, 3, BOB);
	Integer c(128, 1, PUBLIC);
	for(int i = 0; i < 10000; ++i) {
			cf.compute((block*)c.bits, (block*)a.bits, (block*)b.bits);
	}
	cout << time_from(start)<<" "<<party<<" "<<c.reveal<string>(BOB)<<endl;

}
int main(int argc, char** argv) {
	parse_party_and_port(argv, &party, &port);
	NetIO* io = new NetIO(party==ALICE?nullptr:"127.0.0.1", port);

	setup_semi_honest(io, party);
	test();
	
	delete io;
}

1111111111100110011011001101010111110101111001101111111101101100011100110001101100001001111000010101101011100010110111001100001000111110110111110011001101000100010111101001101100100111001111101001011010011000110010011010111011011001000110011101110100110100
1111111111100110011011001101010111110101111001101111111101101100011100110001101100001001111000010101101011100010110111001100001000111110110111110011001101000100010111101001101100100111001111101001011010011000110010011010111011011001000110011101110100110100