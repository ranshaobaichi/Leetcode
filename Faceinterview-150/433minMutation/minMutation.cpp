#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> G;
    unordered_map<string, bool> vis;
    inline bool diffByOneChar(const string& s1, const string& s2) {
        if (s1.length() != s2.length())
            return false;
        
        int diffCount = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                diffCount++;
                if (diffCount > 1)
                    return false;
            }
        }
        return diffCount == 1;
    }

    void build(string cur, string& startGene, string& endGene, vector<string>& bank)
    {
        vis[cur] = false;
        if (diffByOneChar(cur, startGene))
            G[cur].push_back(startGene);
        for (auto s : bank)
            if (diffByOneChar(cur, s))
                G[cur].push_back(s);
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        build(startGene, startGene, endGene, bank);
        for (auto gene : bank) build(gene, startGene, endGene, bank);

        queue<string> q;
        q.push(startGene);
        vis[startGene] = true;
        int ans = -1;
        while (!q.empty())
        {
            ans++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto cur = q.front();
                q.pop();

                if (cur == endGene)
                    return ans;
                for (auto linked : G[cur])
                    if (!vis[linked])
                    {
                        vis[linked] = true;
                        q.push(linked);
                    }
            }
        }
        return -1;
    }
};

int main()
{
    string start = "AACCGGTT";
    string end = "AACCGCTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    Solution p;
    p.minMutation(start, end, bank);
    return 0;
}