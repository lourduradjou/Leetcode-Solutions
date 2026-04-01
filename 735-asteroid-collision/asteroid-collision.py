class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for num in asteroids:
            skip = False

            while stack and stack[-1] > 0 and num < 0:
                if stack[-1] < abs(num):
                    stack.pop()
                    continue
                elif stack[-1] == abs(num):
                    stack.pop()
                
                # equal case or num having lesser value skip it
                skip = True
                break
            
            if not skip:
                stack.append(num)
        
        return stack