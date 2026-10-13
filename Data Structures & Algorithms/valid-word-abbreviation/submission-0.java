class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int i=0,j=0;
        while(i<word.length() && j< abbr.length()){
            char wd=word.charAt(i);
            char ab=abbr.charAt(j);
            if(Character.isDigit(ab)){
                if(ab=='0'){
                    return false;
                }
                int number=0;
                while(j<abbr.length() &&
                Character.isDigit(abbr.charAt(j))){
                    number=number*10 + (abbr.charAt(j)-'0');
                    j++;
                }
                i=i+number;
            }
            else{
                if(wd!=ab) {
                    return false;
                }
                i++;
                j++;
            }
        }
        return i==word.length() && j== abbr.length();
    }
}