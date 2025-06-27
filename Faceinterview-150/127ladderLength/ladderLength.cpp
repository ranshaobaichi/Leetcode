#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    unordered_map<string, vector<string>> G;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // build the Graph
        build(beginWord);
        for (auto s : wordList)
            build(s);

        // use bfs to find the ans
        return bfs(beginWord, endWord);
    }
private:
    void build(string word)
    {
        int l = word.length();
        for (int i = 0; i < l; i++)
        {
            string tmp(word);
            tmp[i] = '*';
            G[word].push_back(tmp);
            G[tmp].push_back(word);
        }
    }
    int bfs(string &beginWord, string &endWord)
    {
        int steps = 0;
        queue<string> q;
        unordered_set<string> vis;
        q.push(beginWord);
        vis.insert(beginWord);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto word = q.front();
                q.pop();
                if (word == endWord)
                    return steps / 2 + 1;

                for (auto s : G[word])
                {
                    if (vis.count(s) == 0)
                    {
                        vis.insert(s);
                        q.push(s);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution s;
    cout << s.ladderLength(beginWord, endWord, wordList);
    return 0;
}