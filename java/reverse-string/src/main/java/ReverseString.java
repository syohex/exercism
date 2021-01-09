class ReverseString {

    String reverse(String inputString) {
        byte[] b = inputString.getBytes();
        for (int i = 0; i < b.length / 2; i++) {
            byte tmp = b[i];
            b[i] = b[b.length - i - 1];
            b[b.length - i - 1] = tmp ;
        }

        return new String(b);
    }
  
}
