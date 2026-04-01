class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        
        inputGroupedData = [
            [pos, health if direction == "R" else -health] for pos,health,direction in zip(positions, healths, directions)
        ]

        sortedInputGroupedData = sorted(inputGroupedData, key = lambda x: x[0])

        stack = []

        for data in sortedInputGroupedData:
            skip = False

            while stack and stack[-1][1] > 0 and data[1] < 0:
                # print(stack[-1])
                if stack[-1][1] < abs(data[1]):
                    stack.pop()
                    data[1] += 1
                    continue
                elif stack[-1][1] > abs(data[1]):
                    stack[-1][1] -= 1
                elif stack[-1][1] == abs(data[1]):
                    # print(stack[-1][1], " ", data[1])
                    stack.pop()
                skip = True
                break
            
            if not skip:
                stack.append(data)
        
        surviving = {x[0]: abs(x[1]) for x in stack}
        # print("stack + ", stack)
        # print("surviving = ",surviving)
    
        ans = []
        for data in inputGroupedData:
            if data[0] in surviving:
                ans.append(surviving[data[0]])

        # print("ans ",ans)
        return ans