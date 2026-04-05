class Solution:
    def judgeCircle(self, moves: str) -> bool:
        start = [0,0]

        for move in moves:
            if move == 'U':
                start[0] = start[0] - 1
            elif move == 'D':
                start[0] = start[0] + 1
            elif move == 'L':
                start[1] = start[1] - 1
            else:
                start[1] = start[1] + 1
        
        if start[0] == 0 and start[1] == 0:
            return True
        else:
            return False