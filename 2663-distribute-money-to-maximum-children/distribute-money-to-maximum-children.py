class Solution:
    def distMoney(self, money: int, children: int) -> int:
        sum = money - children
        if sum < 0:
            return -1 
        
        possibleChildren = sum // 7
        remChildren = children - possibleChildren
        remMoney = sum % 7

        # case one is we can give the distribute 8 count money properly but still we have rem monye
        # in this case give the remaining money to the last person
        if (remChildren == 0 and remMoney != 0):
            return children - 1
        
        # in this case also give the rem money to the last children, we have lot of 7 in this case think!
        if (remChildren < 0) :
            return children - 1

        if (remChildren == 1 and remMoney == 3) :
            return possibleChildren - 1
        
        # if the rem child is greater than one or any other case just return the possibel child thats all
        # possible edges cases we handled here
        return possibleChildren