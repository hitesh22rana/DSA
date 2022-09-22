func reverseWords(s string) string {
    var (
        ans string
        str string
    )
    
    for _, ch := range(s) {
        if(ch == ' ') {
            ans += str + " "
            str = ""
            continue
        }
        
        str = string(ch) + str
    }
    
    return ans + str
}