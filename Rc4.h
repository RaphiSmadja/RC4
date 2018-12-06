//
// Created by raphael on 24/10/18.
//

#ifndef RC4_RC4_H
#define RC4_RC4_H

#include <string>

using namespace std;
namespace Rc4 {
    namespace sequential {
        class Rc4{
        public:
            void ksa(string key){
                string S;
                for (int i = 0; i < 255; ++i) {
                    S[i] = i;
                }
                int j = 0;
                for (int i = 0; i < 255 ; ++i) {
                    j = (j +S[i] + key[i % key.length()]) % 256;
                    swap(S[i],S[j]);
                }
            }
        };
    };
}
/** Google test, Valgrind, Google Benchmark **/

#endif //RC4_RC4_H
