package tp1.ejercicio9;

import java.util.Stack;

public class TestBalanceo {

    public static boolean estaBalanceado(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            // Si es un carácter de apertura, lo agregamos a la pila
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } 
            // Si es un carácter de cierre, verificamos la pila
            else if (c == ')' || c == ']' || c == '}') {
                if (stack.isEmpty()) {
                    return false; // No hay un carácter de apertura correspondiente
                }
                char top = stack.pop();
                if (!coincide(top, c)) {
                    return false; // El carácter de apertura no coincide con el de cierre
                }
            }
        }

        // Si la pila está vacía al final, el string está balanceado
        return stack.isEmpty();
    }

    // Método auxiliar para verificar si los caracteres coinciden
    private static boolean coincide(char apertura, char cierre) {
        return (apertura == '(' && cierre == ')') ||
               (apertura == '[' && cierre == ']') ||
               (apertura == '{' && cierre == '}');
    }

    public static void main(String[] args) {
        // Ejemplo de uso
        String test1 = "{( ) [ ( ) ] }";
        String test2 = "( [ ) ]";

        System.out.println("¿Está balanceado \"" + test1 + "\"? " + estaBalanceado(test1));
        System.out.println("¿Está balanceado \"" + test2 + "\"? " + estaBalanceado(test2));
    }
}