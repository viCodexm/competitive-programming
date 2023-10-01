Trie или prefix tree представляет собой дерево, где каждый node может иметь множество потомков, состоящих из допустимых символов, например буквы английского алфавита  
При вставке последней буквы слова она помечается как `конечная`, что пригождается при проверке есть ли такое слово.  
Пример:  
```
Trie trie;
trie.insert("app");
trie.insert("apple");
trie.search("app"); // returns True
trie.search("melon"); // returns False
trie.insert("aroma");
```
    a
    | \
    p   r
    |    \
    p*     o
    |       \
    l        m
    |        |
    e*       a*
`*- конечная`
