#!/usr/bin/env python
#! coding:utf-8

from itertools import product
from math import factorial

"""
N*Mのボードの各マスに石がある。
各マスの石同士の距離は以下のように定義される。
z = max{|xA-xB|, |yA-yB|}
同じ距離の関係を維持できるなら交換することができる。
関係を維持しつつ、ボードの石のパターン数を求める問題。
"""


class FoxStones:
    def __init__(self):
        pass

    @classmethod
    def getCount(cls, N, M, sx, sy):
        state = {}
        MOD = 1000000009

        for j,i in product(range(1,N+1), range(1,M+1)):
            key = tuple([max(abs(j-x), abs(i-y)) for x,y in zip(sx,sy)])
            if state.has_key(key):
                state[key] += 1
            else :
                state[key] = 1

        return reduce(lambda a,b: (a * (factorial(b) % MOD)) % MOD, state.values(), 1)

def main():
    print FoxStones.getCount(6,1,[3],[1]) # 4
    print FoxStones.getCount(2,2,[2],[1]) # 6
    print FoxStones.getCount(3,3,[1,2,3],[1,2,3]) # 8
    print FoxStones.getCount(12,34,[5,6,7,8,9,10],[11,12,13,14,15,16])
    print FoxStones.getCount(200,200,[26, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200],[50, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200])

if __name__ == "__main__":
    main()
