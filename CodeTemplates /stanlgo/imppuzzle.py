# code for impossible puzzle
# X and Y are two different integers, greater than 1, with sum less than 100. S and P are two mathematicians; S knows the sum X+Y, P knows the product X*Y, and both know the information in these two sentences. The following conversation occurs.

# P says "I cannot find these numbers."
# S says "I was sure that you could not find them. I cannot find them either."
# P says "Then, I found these numbers."
# S says "If you could find them, then I also found them."
# What are these numbers?

from collections import Counter
 
all_pairs=set((a,b) for a in range(2,100) for b in range(a+1,100) if a+b<100)
 
def decompose_sum(s):
    return [(a,s-a) for a in range(2,int(s/2+1))]
 
_prod_counts=Counter(a*b for a,b in all_pairs)
unique_products=set((a,b) for a,b in all_pairs if _prod_counts[a*b]==1)
 
# Find all pairs, for which no of sum decomposition has unique product
# In other words, for which all sum decompositions have non-unique product
s_pairs=[(a,b) for a,b in all_pairs if
    all((x,y) not in unique_products for (x,y) in decompose_sum(a+b))]
 
# Since product guy now knows, possible pairs are those out of above for which product is unique
product_pairs=[(a,b) for a,b in s_pairs if Counter(c*d for c,d in s_pairs)[a*b]==1]
 
# Since the sum guy now knows
final_pairs=[(a,b) for a,b in product_pairs if Counter(c+d for c,d in product_pairs)[a+b]==1]
 
print(final_pairs) # [(4, 13)]