class Solution {
  public boolean isValid(String s) {
      Stack<Character> stack = new Stack<>();

      if (s.length() <= 1) return false;

      // Push opening brackets onto the stack and when a closing bracket appears, check the top of the stack and ensure it matches the corresponding opening bracket.
      for (char c: s.toCharArray()) {
        if (c == '(' || c == '{' || c == '[')
          stack.push(c);
        else if (stack.isEmpty()) {
          return false;
        }
        else {
          char top = stack.pop();
          if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) 
            return false;
        }
      }

      if (stack.isEmpty())
        return true;
      
      return false;
    }
}