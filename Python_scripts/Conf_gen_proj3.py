unit1 = [32,64]                 # L1 cache size
unit2 = [1,2]                   # L1 cache assoc
unit3 = [128,256]               # L2 cache size
unit4 = [4,8]                   # L2 cache assoc
configs_to_test = []
p = 0
   
for j in unit1:
        i = [0]*17                                  ##Define constant parameters here
        i[10] = 2
        i[11] = i[12] = 1
        i[0] = i[1] = 32
        i[2] = i[3] = 64
        i[4] = 64
        i[5] = 24
        i[13] = 8
        i[14] = 4
        i[7] = i[9] = j
        for k in unit2:
            i[6] = i[8] = k
            for l in unit3:
                i[15] = l
                for m in unit4:
                    i[16] = m
                    configs_to_test.append(i)
                    print "c",p,"=",i
                    p += 1

'''
stri = []
for k in range(0,16):
        l = "c"+str(k)
        stri.append(l)
print list(stri)
'''
