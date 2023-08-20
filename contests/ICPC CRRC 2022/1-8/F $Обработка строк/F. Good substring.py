vowel = ["a", "e", "i", "o", "u"]
s = input()
k = int(input())
len_vowel = len_consonant = 0
max_len = cur_len = 0
for i in range(len(s)):
    if s[i] in vowel:
        if len_consonant >= k:
            cur_len = k - 1
 
        len_consonant = 0
        len_vowel += 1
 
        if len_vowel < k:
            cur_len += 1
        else:
            if cur_len > max_len:
                max_len = cur_len
    else:
        if len_vowel >= k:
            cur_len = k - 1
 
        len_vowel = 0
        len_consonant += 1
 
        if len_consonant < k:
            cur_len += 1
        else:
            if cur_len > max_len:
                max_len = cur_len
 
if cur_len > max_len:
    max_len = cur_len
print(max_len)