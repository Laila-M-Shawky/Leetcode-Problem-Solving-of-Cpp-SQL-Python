class Solution(object):
    def rotateTheBox(self, boxGrid):
        """
        :type boxGrid: List[List[str]]
        :rtype: List[List[str]]
        """

        m = len(boxGrid)
        n = len(boxGrid[0])

        # Copy the box
        box = [row[:] for row in boxGrid]

        # Step 1: Apply gravity to the right
        for r in range(m):
            empty = n - 1   # rightmost available empty position

            for c in range(n - 1, -1, -1):
                if box[r][c] == '*':
                    empty = c - 1

                elif box[r][c] == '#':
                    box[r][c], box[r][empty] = box[r][empty], box[r][c]
                    empty -= 1

        # Step 2: Rotate 90 degrees clockwise
        rotated = [[None for _ in range(m)] for _ in range(n)]

        for r in range(m):
            for c in range(n):
                rotated[c][m - 1 - r] = box[r][c]

        return rotated