# (rand_X() - 1) × Y + rand_Y() ==> 
# 可以等概率的生成[1, X * Y]范围的随机数

def rand10():
    while True:
        a = rand7()
        b = rand7()
        num = (a - 1) * 7 + b # rand49

        if num <= 40:
            return num%10 + 1
        
        a = num - 40 # rand9
        b = rand7()
        num = (a - 1) * 7 + b #rand63
        if num <= 60:
            return num%10 + 1
        
        a = num - 60 # rand3
        b = rand7()
        num = (a -1) * 7 + b #rand21
        if num <= 20:
            return num%10 + 1