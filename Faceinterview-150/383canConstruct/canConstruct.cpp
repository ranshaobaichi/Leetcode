bool canConstruct(char* ransomNote, char* magazine) {
    int cnt[26];
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;
    while (*magazine != '\0')
    {
        cnt[*magazine - 'a']++;
        magazine++;
    }
    while(*ransomNote != '\0')
    {
        cnt[*ransomNote - 'a']--;
        if (cnt[*ransomNote - 'a'] < 0)
            return false;
        ransomNote++;
    }
    return true;
}