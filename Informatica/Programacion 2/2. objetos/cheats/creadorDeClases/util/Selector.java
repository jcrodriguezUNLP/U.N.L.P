package util;

import ui.Estilo;
import ui.MenuUI;
import ui.Consola;

public class Selector {

    /**
     * Permite seleccionar una opción de una lista usando un cursor visual.
     * El usuario puede usar 'w' (arriba), 's' (abajo) o el número directamente.
     * Presionar ENTER sin escribir nada selecciona la opción actual.
     */
    public static int seleccionar(String titulo, String[] opciones) {
        int seleccionado = 0;
        boolean confirmado = false;

        while (!confirmado) {
            Estilo.limpiarPantalla();
            MenuUI.mostrarBanner();
            System.out.println(Estilo.CIAN + Estilo.NEGRITA + titulo + Estilo.RESET + "\n");

            for (int i = 0; i < opciones.length; i++) {
                if (i == seleccionado) {
                    System.out.println(Estilo.VERDE + Estilo.NEGRITA + "  » " + opciones[i] + Estilo.RESET);
                } else {
                    System.out.println(Estilo.BLANCO + "    " + opciones[i] + Estilo.RESET);
                }
            }

            System.out.println(Estilo.AZUL + "\n[W: Arriba | S: Abajo | ENTER: Seleccionar | o escribe el Nro]" + Estilo.RESET);
            System.out.print("» ");
            
            String entrada = Consola.leerLinea().toLowerCase().trim();

            if (entrada.isEmpty()) {
                confirmado = true;
            } else if (entrada.equals("w")) {
                seleccionado = (seleccionado > 0) ? seleccionado - 1 : opciones.length - 1;
            } else if (entrada.equals("s")) {
                seleccionado = (seleccionado < opciones.length - 1) ? seleccionado + 1 : 0;
            } else {
                try {
                    int num = Integer.parseInt(entrada) - 1;
                    if (num >= 0 && num < opciones.length) {
                        seleccionado = num;
                        confirmado = true;
                    }
                } catch (NumberFormatException e) {
                    // Ignorar entradas inválidas
                }
            }
        }
        return seleccionado;
    }
}
