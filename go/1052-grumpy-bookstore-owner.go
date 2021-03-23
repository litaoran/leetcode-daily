func maxSatisfied(customers []int, grumpy []int, X int) int {
    total :=0
    res :=0
    for i:=0; i< len(customers) ; i++ {
        if grumpy[i]==0 {
            total += customers[i]
        }
    }
    
    i:=0
    for j:=0;j<len(customers);j++ {
        if grumpy[j]==1 {
            total += customers[j] // not happy -> forced happy
        }
        if j-i+1> X {
            if grumpy[i]==1 {
                total -= customers[i]  // forced happy -> not happy
            }
            i++
        }
        if total > res {
            res = total
        }
    }
    
    return res
}
