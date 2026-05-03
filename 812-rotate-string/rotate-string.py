class Solution(object):
    def rotateString(self, s, goal):
        if len(s) != len(goal):
            return False

        if len(s) == 0:
            return True

        for start in range(len(goal)):
            i = 0
            j = start

            while i < len(s) and s[i] == goal[j % len(goal)]:
                i += 1
                j += 1

            if i == len(s):
                return True

        return False