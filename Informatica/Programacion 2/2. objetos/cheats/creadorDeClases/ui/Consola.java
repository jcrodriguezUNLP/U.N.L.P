package ui;

import java.util.Scanner;

public class Consola {
    private static Scanner in = new Scanner(System.in);

    public static String leerLinea() {
        return in.nextLine();
    }

    public static int leerEntero() {
        try {
            int val = Integer.parseInt(in.nextLine());
            return val;
        } catch (NumberFormatException e) {
            return -1;
        }
    }

    public static String leerSino(String mensaje) {
        String respuesta;
        do {
            System.out.print(mensaje + " (s/n): ");
            respuesta = in.nextLine().trim().toLowerCase();
        } while (!respuesta.equals("s") && !respuesta.equals("n"));
        return respuesta;
    }
}
