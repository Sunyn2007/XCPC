// #include <cstdio>
// #include <vector>
// #include <algorithm>
// #include <functional>

// char str[500010];

// int main() {
//     int n, k;scanf("%d%d", &n, &k);
//     scanf("%s", str);
//     std::vector<int> v(n);
//     for(int i=0;i<n;++i)
//         v[i] = str[i] - '0';
//     std::vector<int> pre(n), suf(n);
//     pre[0] = v[0];
//     for(int i=1;i<n;++i) {
//         pre[i] = pre[i-1] + v[i];
//     }
//     suf[n-1] = v[n-1];
//     for(int i=n-2;i>=0;--i) {
//         suf[i] = suf[i+1] + v[i];
//     }
//     std::vector<int> ans;
//     for(int w=1;w<=n;++w) {
//         int tmp = 4 * pre[n-1];
//         printf("tmp[%d] %d\n", w, tmp);
//         //left
//         for(int t=0;t<n;t+=w) {
//             tmp -= v[t];
//         }
//         printf("tmp[%d] %d\n", w, tmp);
//         //right
//         for(int t=w;t<=n;t+=w) {
//             tmp -= v[t-1];
//         }
//         printf("tmp[%d] %d\n", w, tmp);
//         //top
//         tmp -= pre[w-1];
//         printf("tmp[%d] %d\n", w, tmp);
//         //bottom
//         tmp -= suf[n-w];
//         printf("tmp[%d] %d\n", w, tmp);
//         ans.push_back(tmp);
//     }
//     std::sort(ans.begin(), ans.end(), std::greater<int>());
//     printf("%d\n", ans[k-1]);


//     return 0;
// }

#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;
const double pi = acos(-1);

int log2(int x) {
    int ans = -1;
    for(;x;x>>=1)++ans;
    return ans;
}

template<int64 M>
class Int {
private:
    int64 v;
public:
    Int():v(){}
    Int(const Int& b) {
        v = b.v;
    }
    Int(Int&& b) {
        v = b.v;
    }
    Int(int64 x) {
        if(x<0) {
            v = (x%M)+M;
            if(v==M)v = 0;
        } else if (x >= M) {
            v = x % M;
        } else {
            v = x;
        }
    }
    Int& operator = (const Int& b) {
        v = b.v;
        return *this;
    }
    Int& operator = (Int&& b) {
        v = b.v;
        return *this;
    }
    Int operator + (Int b) const {
        return v + b.v;
    }
    Int operator - (Int b) const {
        return v - b.v;
    }
    Int operator * (Int b) const {
        return v * b.v;
    }
    Int& operator += (Int b) {
        v += b.v;
        if(v >= M)
            v -= M;
        return *this;
    }
    Int& operator -= (Int b) {
        v -= b.v;
        if(v < 0)
            v += M;
        return *this;
    }
    Int& operator *= (Int b) {
        v = (v * b.v) % M;
        return *this;
    }
    Int operator ^ (uint64 b) const {
        Int ans = 1;
        Int base = *this;
        for(;b;b>>=1) {
            if(b&1)
                ans *= base;
            base *= base;
        }
        return ans;
    }
    int64 val() const {return v;}
};

std::vector<std::complex<double> > FFT(std::vector<std::complex<double> > a, int len) {
    // std::vector<std::complex<double> > ans;
    len = (1<<(log2(len-1)+1));
    a.resize(len);
    // ans.resize(len);
    int log2len = log2(len);
    for(int i=1,j=len/2;i<len-1;++i) {
        if(i<j) {
            std::swap(a[i], a[j]);
        }

        int k = len/2;
        while(j >= k) {
            j -= k;
            k>>=1;
        }
        j += k;
    }
    for(int t=0;t<log2len;++t) {
        int n_2 = (1<<t);
        int n = (n_2<<1);
        std::complex<double> wn(cos(pi/n_2), sin(pi/n_2));
        // std::complex<double> w(1, 0);
        for(int j=0;j<len;j+=n) {
            std::complex<double> w(1, 0);
            for(int i=j;i<j+n_2;++i) {
                std::complex<double> ta = a[i], tb = w * a[i+n_2];
                a[i] = ta + tb;
                a[i+n_2] = ta - tb;
                w *= wn;
            }
        }
    }
    return a;
}

template<int64 M>
std::vector<Int<M> > NTT(std::vector<Int<M> > a, int len, int64 g) {
    len = (1<<(log2(len-1)+1));
    a.resize(len);
    int log2len = log2(len);
    for(int i=1,j=len/2;i<len-1;++i) {
        if(i<j) {
            std::swap(a[i], a[j]);
        }

        int k = len/2;
        while(j >= k) {
            j -= k;
            k>>=1;
        }
        j += k;
    }
    for(int t=0;t<log2len;++t) {
        int n_2 = (1<<t);
        int n = (n_2<<1);
        Int<M> wn(Int<M>(g)^((M-1)/n));
        // Int<M> w(1, 0);
        for(int j=0;j<len;j+=n) {
            Int<M> w(1);
            for(int i=j;i<j+n_2;++i) {
                Int<M> ta = a[i], tb = w * a[i+n_2];
                a[i] = ta + tb;
                a[i+n_2] = ta - tb;
                w *= wn;
            }
        }
    }
    return a;
}

class Poly {
private:
public:
    std::vector<std::complex<double> > v;
    int deg() const {return v.size()-1;}
    Poly():v(){}
    Poly(std::vector<std::complex<double> >&& vec) {
        v = std::move(vec);
    }
    Poly operator + (const Poly& b) const {
        Poly ans;
        ans.v.resize(std::max(deg()+1, b.deg()+1));
        for(int i=0;i<=ans.deg();++i)
            ans.v[i] = v[i] + b.v[i];
        return ans;
    }
    Poly operator - (const Poly& b) const {
        Poly ans;
        ans.v.resize(std::max(deg()+1, b.deg()+1));
        for(int i=0;i<=ans.deg();++i)
            ans.v[i] = v[i] - b.v[i];
        return ans;
    }
    Poly operator * (const Poly& b) const {
        std::vector<std::complex<double> > pa, pb;
        pa = FFT(v, deg()+b.deg()+1);
        pb = FFT(b.v, deg()+b.deg()+1);
        int n = pa.size();
        for(int i=0;i<n;++i)
            pa[i] *= pb[i];
        pa = FFT(pa, n);
        pb[0] = pa[0] / (double)n;
        for(int i=1;i<(int)pb.size();++i) {
            pb[i] = pa[n-i] / (double)n;
        }
        pb.resize(deg()+b.deg()+1);
        return pb;
    }
    friend std::ostream& operator << (std::ostream& stream, const Poly& poly) {
        for(auto x:poly.v) {
            stream << x ;
        }
        stream << std::endl;
        return stream;
    }
};

template<int64 M, int64 g>
class PolyMod {
private:
public:
    std::vector<Int<M> > v;
    int deg() const {return v.size()-1;}
    PolyMod():v(){}
    PolyMod(std::vector<Int<M> >&& vec) {
        v = std::move(vec);
    }
    PolyMod operator + (const PolyMod& b) const {
        PolyMod ans;
        ans.v.resize(std::max(deg()+1, b.deg()+1));
        for(int i=0;i<=ans.deg();++i)
            ans.v[i] = v[i] + b.v[i];
        return ans;
    }
    PolyMod operator - (const PolyMod& b) const {
        PolyMod ans;
        ans.v.resize(std::max(deg()+1, b.deg()+1));
        for(int i=0;i<=ans.deg();++i)
            ans.v[i] = v[i] - b.v[i];
        return ans;
    }
    PolyMod operator * (const PolyMod& b) const {
        std::vector<Int<M> > pa, pb;
        pa = NTT(v, deg()+b.deg()+1, g);
        pb = NTT(b.v, deg()+b.deg()+1, g);
        int n = pa.size();
        for(int i=0;i<n;++i)
            pa[i] *= pb[i];
        pa = NTT(pa, n, g);
        Int<M> n_inv = (Int<M>(n)^(M-2));
        pb[0] = pa[0] * n_inv;
        for(int i=1;i<(int)pb.size();++i) {
            pb[i] = pa[n-i] * n_inv;
        }
        pb.resize(deg()+b.deg()+1);
        return pb;
    }
    friend std::ostream& operator << (std::ostream& stream, const PolyMod& poly) {
        for(auto x:poly.v) {
            stream << x.val() << ' ' ;
        }
        stream << std::endl;
        return stream;
    }
};

char str[1000010];

int main() {
    PolyMod<998244353, 3> a, b, c;
    int n, k;scanf("%d%d", &n, &k);
    scanf("%s", str);
    std::vector<int> v(n);
    for(int i=0;i<n;++i)
        v[i] = str[i] - '0';
    for(int i=0;i<n;++i)
        a.v.push_back(v[i]);
    for(int i=n-1;i>=0;--i)
        b.v.push_back(v[i]);
    c = a * b;
    std::vector<int> pre(n), suf(n);
    pre[0] = v[0];
    for(int i=1;i<n;++i) {
        pre[i] = pre[i-1] + v[i];
    }
    suf[n-1] = v[n-1];
    for(int i=n-2;i>=0;--i) {
        suf[i] = suf[i+1] + v[i];
    }
    std::vector<int> anstb;
    for(int w=1;w<=n;++w) {
        int tmp = 2 * pre[n-1];
        //top
        tmp -= pre[w-1];
        //bottom
        tmp -= suf[n-w];

        tmp -=  (c.v[n-1-w].val()) + (c.v[n-1+w].val());
        anstb.push_back(tmp);
    }
    std::vector<int> anslr;
    int base = 0;
    for(int i=1;i<n;++i)
        if(v[i-1] == 0)
            base += v[i];
    for(int i=0;i<n-1;++i)
        if(v[i+1] == 0) 
            base += v[i];
    for(int w=1;w<=n;++w) {
        int tmp = base;
        //left
        for(int t=0;t<n;t+=w) {
            tmp -= v[t];
        }
        //right
        for(int t=w;t<=n;t+=w) {
            tmp -= v[t-1];
        }
        tmp += v[0];
        if(n%w==0)
            tmp += v[n-1];
        anslr.push_back(tmp);
    }
    std::vector<int> ans;
    for(int w=1;w<=n;++w) {
        ans.push_back(anslr[w-1] + anstb[w-1]);
        // printf("ans [%d] = %d %d %d\n", w, ans.back(), anslr[w-1], anstb[w-1]);
    }
    std::sort(ans.begin(), ans.end(), std::greater<int>());
    printf("%d\n", ans[k-1]);

    return 0;
}