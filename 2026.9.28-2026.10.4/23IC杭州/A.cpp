// #include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using std::cin;
using std::cout;
using std::cerr;
using std::string;
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;

struct Score {
    int sol, pnl;
    Score():sol(), pnl(){}
    Score(int a, int b):sol(a), pnl(b){}
};
bool operator < (Score a, Score b) {
    if(a.sol == b.sol)
        return a.pnl < b.pnl;
    return a.sol > b.sol;
}
bool operator == (Score a, Score b) {
    return a.sol == b.sol && a.pnl == b.pnl;
}

void solve() {
    int m;cin >> m;
    std::map<string, int> teamid;
    int n = 0;
    std::vector<string> teambyid(1);
    std::vector<std::vector<std::vector<std::pair<int, int> > > > record(26);
    std::vector<std::vector<int> > mint(26);
    for(int c = 0; c < 26; ++c)
        record[c].resize(1);
    for(int c = 0; c < 26; ++c)
        mint[c].resize(1);
    for(int itm = 1; itm <= m; ++itm) {
        string team, probstr, status;
        int time;
        cin >> team >> probstr >> time >> status;
        cerr << itm << ' ' << m << ' ' << team << ' ' << probstr << ' ' << time << ' ' << status << '\n';
        int tid;
        if(teamid.find(team) == teamid.end()) {
            tid = ++n;
            teamid[team] = tid;
            teambyid.emplace_back(team);
            for(int c = 0; c < 26; ++c)
                record[c].emplace_back().emplace_back();
            for(int c = 0; c < 26; ++c)
                mint[c].emplace_back(-1);
        } else {
            tid = teamid[team];
        }
        int prob = probstr[0] - 'A';
        mint[prob][tid] = time;
        if(status == "accepted") {
            record[prob][tid].back().first += time;
            record[prob][tid].back().second = time + 1;
            record[prob][tid].emplace_back();
        } else {
            record[prob][tid].back().first += 20;
        }
    }
    std::vector<Score> scr(n + 2);
    for (int i = 1; i <= n; ++i) {
        for(int c = 0; c < 26; ++c) {
            if(record[c][i][0].second) {
                scr[i].sol++;
                scr[i].pnl += record[c][i][0].first;
            }
        }
    }


    int gtcnt = 0;
    for (int i = 1; i <= n; ++i) {
        if(scr[i].sol)
            ++gtcnt;
    }
    __gnu_pbds::tree<std::pair<Score, int>, __gnu_pbds::null_type, std::less<std::pair<Score, int> >, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>
        tree;
    for (int i = 1; i <= n; ++i) {
        tree.insert({scr[i], i});
    }

    std::vector<int> seq;
    for (auto [scr, id] : tree) {
        seq.emplace_back(id);
    }

    auto add = [&tree, &gtcnt](Score scr, int id)-> void {
        tree.insert({scr, id});
        if(scr.sol)
            ++gtcnt;
    };

    auto del = [&tree, &gtcnt](Score scr, int id)-> void {
        tree.erase({scr, id});
        if(scr.sol)
            --gtcnt;
    };

    auto check = [&tree, &gtcnt](Score scr)-> bool {
        int lim;
        if(gtcnt % 10) lim = gtcnt / 10 + 1;
        else lim = gtcnt / 10;
        lim = std::min(lim, 35);
        if(tree.order_of_key({scr, 0}) < lim)
            return true;
        return false;
    };

    std::vector<Score> minscr(n + 2), maxscr(n + 2);
    for (int i = 1; i <= n; ++i)
        minscr[i] = scr[i];
    for (int i = 1; i <= n; ++i)
        maxscr[i] = scr[i];
    
    int empmx_id = 0;
    Score empmx;

    for (int i = 1; i <= n; ++i) {
        for (int c = 0; c < 26; ++c) {
            if(mint[c][i] == -1)
                continue;
            Score cur = scr[i];
            if(record[c][i][0].second){
                cur.pnl -= record[c][i][0].first;
                cur.sol --;
            }
            cur.pnl += mint[c][i];
            cur.sol ++;
            minscr[i] = std::min(minscr[i], cur);
            if(scr[i].sol == 0) {
                if(empmx < cur) {
                    empmx = cur;
                    empmx_id = i;
                }
            }

            cur = scr[i];
            if(record[c][i][0].second) {
                cur.pnl -= record[c][i][0].first;
                cur.sol --;
                if(record[c][i][1].second) {
                    cur.pnl += record[c][i][0].first - (record[c][i][0].second - 1) + 20 + record[c][i][1].first;
                    cur.sol ++;
                }
                maxscr[i] = std::max(maxscr[i], cur);
            }
        }
    }

    std::vector<int> ans;
    Score mxscr(200000, 0);
    int mxscrid = 0;
    for (auto tid : seq) {
        if(check(scr[tid])) {
            ans.emplace_back(tid);
            continue;
        }
        bool solved = false;
        del(scr[tid], tid);
        add(minscr[tid], tid);
        if(check(scr[tid])) {
            ans.emplace_back(tid);
            solved = true;
        }
        del(minscr[tid], tid);
        add(scr[tid], tid);
        if(solved)continue;

        if(mxscrid) {
            del(scr[mxscrid], mxscrid);
            add(mxscr, mxscrid);
            if(check(scr[tid])) {
                ans.emplace_back(tid);
                solved = true;
            }
            del(mxscr, mxscrid);
            add(scr[mxscrid], mxscrid);
        }
        if(solved)continue;

        if(empmx_id) {
            del(scr[empmx_id], empmx_id);
            add(empmx, empmx_id);
            if(check(scr[tid])) {
                ans.emplace_back(tid);
                solved = true;
            }
            del(empmx, empmx_id);
            add(scr[empmx_id], empmx_id);
        }
        if(solved)continue;
    }

    cout << ans.size() << '\n';
    for (auto id : ans) {
        cout << teambyid[id] << ' ';
    }
    cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T;cin >> T;
    while(T--)
        solve();

    return 0;
}