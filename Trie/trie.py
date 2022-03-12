class Trie:
    def __init__(self):
        self.root = {}
    
    def insert(self, word):
        node = self.root
        for i in range(0, len(word)):
            if word[i] not in node:
                node[word[i]] = {}
            node = node[word[i]]
        node['#'] = '#'
    
    def find(self, word):
        node = self.root
        for i in range(0, len(word)):
            if word[i] not in node:
                return False
            node = node[word[i]]
        return '#' in node
    
    def find_prefix(self, word):
        node = self.root
        for i in range(0, len(word)):
            if word[i] not in node:
                return False
            node = node[word[i]]
        return True
    
    def find_all_words(self):
        words = []
        
        def dfs(node, word):
            if '#' in node:
                words.append(word)
            for key in node:
                if key != '#':
                    dfs(node[key], word + key)
                    
        dfs(self.root, '')
        
        return words