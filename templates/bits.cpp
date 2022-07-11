#include "template.cpp"

#define isbit(x, b) ((x >> b) & 1)
#define bMask(b) ((1ll << b) - 1)
#define bMsbMask(x) ((1ll << (msb(x) + 1)) - 1)
#define bSetTill(x, b) (((1ll << b) - 1) | x)
#define bUnsetTill(x, b) ((~((1ll << b) - 1)) & x)
#define bSetAfter(x, b) ((~((1ll << b) - 1)) | x)
#define bUnsetAfter(x, b) (((1ll << b) - 1) & x)

int msb(ll a) {
    int res = -1;
    while (a) {
        res++;
        a >>= 1;
    }
    return res;
}
