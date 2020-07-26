from collections import defaultdict

class Solution(object):

    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        L = len(beginWord)
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(L):
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)
        
        queue = [(beginWord, 1)]
        visited = {beginWord: True}

        while queue:
            current_word, level = queue.pop(0)
            for i in range(L):
                intermediate_word = current_word[:i] + "*" + current_word[i+1:]
                for word in all_combo_dict[intermediate_word]:
                    if word == endWord:
                        return level + 1

                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level + 1))
                all_combo_dict[intermediate_word] = []
        return 0


class Solution2(object):

    def __init__(self):
        self.length = 0
        self.neighbors_dict = defaultdict(list)

    def visit_node(self, queue, visited, other_visited):
        current_word, level = queue.pop(0)
        
        for i in range(self.length):
            intermediate_word = current_word[:i] + "*" + current_word[i+1:]

            for word in self.neighbors_dict[intermediate_word]:
                if word in other_visited:
                    return level + other_visited[word]
                if word not in visited:
                    visited[word] = level + 1
                    queue.append((word, level + 1))
        return None

    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        self.length = len(beginWord)
        for word in wordList:
            for i in range(self.length):
                key = word[:i] + "*" + word[i+1:]
                self.neighbors_dict[key].append(word)
        
        queue_begin = [(beginWord, 1)]
        queue_end = [(endWord, 1)]
        visited_begin = {beginWord: 1}
        visited_end = {beginWord: 1}

        ans = None

        while queue_begin and queue_end:
            print(queue_begin)
            print(queue_end)
            ans = self.visit_node(queue_begin, visited_begin, visited_end)
            if ans:
                return ans

            ans = self.visit_node(queue_end, visited_end, visited_begin)
            if ans:
                return ans

        return 0

class SolutionBirDirectionBFS(object):
    def __init__(self):
        self.length = 0
        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        self.all_combo_dict = defaultdict(list)

    def visitWordNode(self, queue, visited, others_visited):
        current_word, level = queue.pop(0)
        for i in range(self.length):
            # Intermediate words for current word
            intermediate_word = current_word[:i] + "*" + current_word[i+1:]

            # Next states are all the words which share the same intermediate state.
            for word in self.all_combo_dict[intermediate_word]:
                # If the intermediate state/word has already been visited from the
                # other parallel traversal this means we have found the answer.
                if word in others_visited:
                    return level + others_visited[word]
                if word not in visited:
                    # Save the level as the value of the dictionary, to save number of hops.
                    visited[word] = level + 1
                    queue.append((word, level + 1))
        return None

    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """

        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        # Since all words are of same length.
        self.length = len(beginWord)

        for word in wordList:
            for i in range(self.length):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                self.all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)


        # Queues for birdirectional BFS
        queue_begin = [(beginWord, 1)] # BFS starting from beginWord
        queue_end = [(endWord, 1)] # BFS starting from endWord

        # Visited to make sure we don't repeat processing same word
        visited_begin = {beginWord: 1}
        visited_end = {endWord: 1}
        ans = None

        # We do a birdirectional search starting one pointer from begin
        # word and one pointer from end word. Hopping one by one.
        while queue_begin and queue_end:
            print(queue_begin)
            print(queue_end)
            # One hop from begin word
            ans = self.visitWordNode(queue_begin, visited_begin, visited_end)
            if ans:
                return ans
            # One hop from end word
            ans = self.visitWordNode(queue_end, visited_end, visited_begin)
            if ans:
                return ans

        return 0


ans = SolutionBirDirectionBFS().ladderLength("top", "iii", ["iop", "ioy", "iiy", "iip", "iii"])
print(ans)