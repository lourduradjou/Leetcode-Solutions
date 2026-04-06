class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        x, y = 0, 0
        directions = [[0,1], [1, 0], [0, -1], [-1, 0]]
        d = 0
        res = 0
        obstacles = {tuple(o) for o in obstacles}

        for command in commands:
            if command == -1:
                d = (d + 1) % 4
            elif command == -2:
                d = (d - 1) % 4
            else:
                dx, dy = directions[d]
                for _ in range(command):
                    if (x+dx, y+dy) in obstacles:
                        break
                    x = x + dx
                    y = y + dy
            
            res = max(res, x**2 + y**2)
        
        return res