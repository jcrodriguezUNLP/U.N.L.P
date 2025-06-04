/*
Resumen de consignas para la solucion logistica:

Entradas:
- Cantidad y tipo de muebles (categoria 1 a 4, cada una con volumen fijo)
    • Categoria de muebles:
        ◦ 1: 1/2 m3
        ◦ 2: 1 m3
        ◦ 3: 2 m3
        ◦ 4: 3 m3
- Cantidad de bultos (cada uno de 1/3 m3)
- Distancia del viaje (en km)
- Dia de la semana del viaje
- Tipo de cliente (normal, anciano, discapacitado, etc.)

Calculos y logica:
- Volumen total a transportar = suma de muebles + bultos
- Asignacion de vehiculos segun volumen:
    • Camion (6 m3)
    • 2 camionetas (2 m3 cada una)
- Asignacion de chofer y ayudante segun dia:
    • Lunes, miercoles, viernes:
        ◦ Camion        -> Pedro (chofer) y Romualdo (ayudante)
        ◦ Camioneta     -> Coco (chofer) y Felicito (ayudante)
        ◦ 2da camioneta -> Garfio (chofer-ayudante)
    • Martes, jueves, sabado:
        ◦ Camion        -> Coco   (chofer) y Felicito (ayudante)
        ◦ Camioneta     -> Pedro  (chofer) y Romualdo (ayudante)
        ◦ 2da camioneta -> Garfio (chofer-ayudante)
    • Domingo:
        ◦ Camion -> Everardo (chofer) y Sifrigedo (ayudante)
        ◦ No se usan las camionetas
- Descuentos/recargos segun dia:
    • Lunes, martes, miercoles: -15%
    • Jueves, viernes, sabado: -8%
    • Domingo: +12%
- Recargo por distancia:
    • Si >48km, +6% (3% x 2)
- Ayudante extra:
    • Si cliente especial, sumar ayudante y su costo

Costos:
- Camion: $25000/hora (transporte)
- Camion: $60000 (chofer)
- Camion: $30000 (ayudante)
- Camioneta: $18000/hora (transporte)
- Camioneta: $40000 (chofer)
- Camioneta: $30000 (ayudante)
- Ayudante extra: $30000

Salidas requeridas:
- Tipo(s) de transporte necesario(s)
- Costo total del viaje (con descuentos/recargos)
- Monto a abonar a choferes y ayudantes
- Dia pactado y nombres de choferes/ayudantes asignados
- Detalle de descuentos/recargos aplicados

El sistema debe:
- Calcular el volumen a transportar
- Asignar vehiculos y personal segun el dia
- Aplicar descuentos/recargos
- Sumar ayudantes si corresponde
- Calcular costos
- Mostrar un resumen detallado del viaje y los pagos
*/

/*
Según la consigna y el resumen:

¿Cuántos pedidos realizo?

El sistema está pensado para un pedido a la vez (un solo cliente por vez).
¿Cuántas categorías de mueble puedo incluir en cada pedido?

Puedes incluir todas las categorías (1, 2, 3 y 4) en el mismo pedido, en la cantidad que desees de cada una.
¿Existe una cantidad máxima de viajes?

No se menciona un máximo de viajes. El sistema debe calcular cuántos vehículos (camión y/o camionetas) se necesitan para transportar todo el volumen en un solo viaje, usando todos los vehículos disponibles si es necesario.
¿Existe una cantidad máxima de m³?

No hay un máximo explícito. El límite práctico es la capacidad total de los vehículos disponibles en un solo viaje:
Camión: 6 m³
2 camionetas: 2 m³ cada una (total 4 m³)
Capacidad total por viaje: 10 m³
Si el volumen supera los 10 m³, el sistema debería indicar que no es posible transportar todo en un solo viaje (o requeriría múltiples viajes, pero la consigna no detalla cómo manejar eso).
En resumen:

Un pedido puede tener cualquier cantidad de muebles de cualquier categoría y bultos.
El sistema calcula si se puede transportar todo en un solo viaje con los vehículos disponibles (máximo 10 m³ por viaje).
Si el volumen excede 10 m³, no se puede realizar el pedido en un solo viaje según los recursos dados.
*/

#include <stdio.h>

#define CANT_CATEGORIAS 4
#define VOLUMEN_CAT1 0.5
#define VOLUMEN_CAT2 1.0
#define VOLUMEN_CAT3 2.0
#define VOLUMEN_CAT4 3.0
#define VOLUMEN_BULTO (1.0/3.0)

#define VOLUMEN_CAMION 6.0
#define VOLUMEN_CAMIONETA 2.0

#define COSTO_CAMION_HORA 25000
#define COSTO_CAMION_CHOFER 60000
#define COSTO_CAMION_AYUDANTE 30000

#define COSTO_CAMIONETA_HORA 18000
#define COSTO_CAMIONETA_CHOFER 40000
#define COSTO_CAMIONETA_AYUDANTE 30000

#define COSTO_AYUDANTE_EXTRA 30000

int main() {
    int cant_cat1, cant_cat2, cant_cat3, cant_cat4;
    int cant_bultos;
    float distancia;
    int dia_semana; // 1=Lunes ... 7=Domingo
    int cliente_especial; // 1=Si, 0=No

    // Ingreso de datos
    printf("Ingrese cantidad de muebles categoria 1 (0.5 m3): ");
    scanf("%d", &cant_cat1);

    printf("Ingrese cantidad de muebles categoria 2 (1 m3): ");
    scanf("%d", &cant_cat2);

    printf("Ingrese cantidad de muebles categoria 3 (2 m3): ");
    scanf("%d", &cant_cat3);

    printf("Ingrese cantidad de muebles categoria 4 (3 m3): ");
    scanf("%d", &cant_cat4);

    printf("Ingrese cantidad de bultos (1/3 m3 cada uno): ");
    scanf("%d", &cant_bultos);

    printf("Ingrese distancia del viaje (en km): ");
    scanf("%f", &distancia);

    printf("Ingrese dia de la semana (1=Lunes ... 7=Domingo): ");
    scanf("%d", &dia_semana);

    printf("Cliente especial? (1=Si, 0=No): ");
    scanf("%d", &cliente_especial);

    // Calculo del volumen total
    float volumen_total = cant_cat1   * VOLUMEN_CAT1 +
                          cant_cat2   * VOLUMEN_CAT2 +
                          cant_cat3   * VOLUMEN_CAT3 +
                          cant_cat4   * VOLUMEN_CAT4 +
                          cant_bultos * VOLUMEN_BULTO ;

    printf("\nVolumen total a transportar: %.2f m3\n", volumen_total);

    // Validacion de capacidad maxima
    if (volumen_total > VOLUMEN_CAMION + 2 * VOLUMEN_CAMIONETA) {
        printf("No es posible transportar todo en un solo viaje con los vehiculos disponibles (maximo 10 m3).\n");
        return 1;
    }

    // Asignacion de vehiculos
    float restante = volumen_total;
    int usa_camion = 0, usa_camioneta1 = 0, usa_camioneta2 = 0;

    // El domingo solo se puede usar el camion
    if (dia_semana == 7) {
        if (restante > VOLUMEN_CAMION) {
            printf("El domingo solo se puede usar el camion (6 m3). No es posible transportar todo.\n");
            return 1;
        }
        usa_camion = 1;
        restante = 0;
    } else {
        // Primero usar el camion si hace falta
        if (restante > 0) {
            if (restante > VOLUMEN_CAMION) {
                usa_camion = 1;
                restante -= VOLUMEN_CAMION;
            } else {
                usa_camion = 1;
                restante = 0;
            }
        }
        // Luego la primer camioneta
        if (restante > 0) {
            if (restante > VOLUMEN_CAMIONETA) {
                usa_camioneta1 = 1;
                restante -= VOLUMEN_CAMIONETA;
            } else {
                usa_camioneta1 = 1;
                restante = 0;
            }
        }
        // Luego la segunda camioneta
        if (restante > 0) {
            if (restante > VOLUMEN_CAMIONETA) {
                usa_camioneta2 = 1;
                restante -= VOLUMEN_CAMIONETA;
            } else {
                usa_camioneta2 = 1;
                restante = 0;
            }
        }
    }

    printf("\nVehiculos asignados:\n");
    if (usa_camion)      printf("- Camion\n");
    if (usa_camioneta1)  printf("- Camioneta 1\n");
    if (usa_camioneta2)  printf("- Camioneta 2\n");

    printf("\nPersonal asignado:\n");

    if (dia_semana == 7) {
        // Domingo: solo camion
        if (usa_camion) {
            printf("- Camion: Chofer: Everardo, Ayudante: Sifrigedo\n");
        }
    } else {
        // Lunes, miercoles, viernes
        if (dia_semana == 1 || dia_semana == 3 || dia_semana == 5) {
            if (usa_camion)
                printf("- Camion: Chofer: Pedro, Ayudante: Romualdo\n");
            if (usa_camioneta1)
                printf("- Camioneta 1: Chofer: Coco, Ayudante: Felicito\n");
            if (usa_camioneta2)
                printf("- Camioneta 2: Chofer/Ayudante: Garfio\n");
        }
        // Martes, jueves, sabado
        if (dia_semana == 2 || dia_semana == 4 || dia_semana == 6) {
            if (usa_camion)
                printf("- Camion: Chofer: Coco, Ayudante: Felicito\n");
            if (usa_camioneta1)
                printf("- Camioneta 1: Chofer: Pedro, Ayudante: Romualdo\n");
            if (usa_camioneta2)
                printf("- Camioneta 2: Chofer/Ayudante: Garfio\n");
        }
    }

    // Calculo de costos base
    int costo_transporte = 0;
    int costo_choferes = 0;
    int costo_ayudantes = 0;
    int costo_ayudante_extra = 0;

    if (usa_camion) {
        costo_transporte += COSTO_CAMION_HORA;
        costo_choferes   += COSTO_CAMION_CHOFER;
        costo_ayudantes  += COSTO_CAMION_AYUDANTE;
    }
    if (usa_camioneta1) {
        costo_transporte += COSTO_CAMIONETA_HORA;
        costo_choferes   += COSTO_CAMIONETA_CHOFER;
        costo_ayudantes  += COSTO_CAMIONETA_AYUDANTE;
    }
    if (usa_camioneta2) {
        costo_transporte += COSTO_CAMIONETA_HORA;
        costo_choferes   += COSTO_CAMIONETA_CHOFER;
        costo_ayudantes  += COSTO_CAMIONETA_AYUDANTE;
    }

    // Ayudante extra si cliente especial
    if (cliente_especial) {
        costo_ayudante_extra = COSTO_AYUDANTE_EXTRA;
        printf("\nSe requiere ayudante extra por tipo de cliente.\n");
    }

    // Descuento o recargo segun el dia
    float factor_descuento = 1.0;
    if (dia_semana == 1 || dia_semana == 2 || dia_semana == 3) { // Lunes, martes, miercoles
        factor_descuento = 0.85;
        printf("\nDescuento aplicado: 15%%\n");
    } else if (dia_semana == 4 || dia_semana == 5 || dia_semana == 6) { // Jueves, viernes, sabado
        factor_descuento = 0.92;
        printf("\nDescuento aplicado: 8%%\n");
    } else if (dia_semana == 7) { // Domingo
        factor_descuento = 1.12;
        printf("\nRecargo aplicado: 12%%\n");
    }

    // Recargo por distancia
    float factor_recargo_dist = 1.0;
    if (distancia > 48) {
        factor_recargo_dist = 1.06;
        printf("Recargo por distancia: 6%%\n");
    }

    // Calculo final
    float costo_total = (costo_transporte * factor_descuento * factor_recargo_dist)
                      + costo_choferes + costo_ayudantes + costo_ayudante_extra;

    printf("\n==============================\n");
    printf("RESUMEN FINAL DEL VIAJE\n");
    printf("==============================\n");
    printf("Dia del viaje: ");
    switch(dia_semana) {
        case 1: printf("Lunes\n"); break;
        case 2: printf("Martes\n"); break;
        case 3: printf("Miercoles\n"); break;
        case 4: printf("Jueves\n"); break;
        case 5: printf("Viernes\n"); break;
        case 6: printf("Sabado\n"); break;
        case 7: printf("Domingo\n"); break;
        default: printf("Dia invalido\n"); break;
    }
    printf("Distancia: %.2f km\n", distancia);
    printf("Cliente especial: %s\n", cliente_especial ? "Si" : "No");
    printf("Muebles categoria 1: %d\n", cant_cat1);
    printf("Muebles categoria 2: %d\n", cant_cat2);
    printf("Muebles categoria 3: %d\n", cant_cat3);
    printf("Muebles categoria 4: %d\n", cant_cat4);
    printf("Bultos: %d\n", cant_bultos);
    printf("Volumen total: %.2f m3\n", volumen_total);

    printf("\nVehiculos utilizados:\n");
    if (usa_camion)      printf("- Camion\n");
    if (usa_camioneta1)  printf("- Camioneta 1\n");
    if (usa_camioneta2)  printf("- Camioneta 2\n");

    printf("\nPersonal asignado:\n");
    if (dia_semana == 7) {
        if (usa_camion) printf("- Camion: Chofer: Everardo, Ayudante: Sifrigedo\n");
    } else {
        if (dia_semana == 1 || dia_semana == 3 || dia_semana == 5) {
            if (usa_camion)      printf("- Camion: Chofer: Pedro, Ayudante: Romualdo\n");
            if (usa_camioneta1)  printf("- Camioneta 1: Chofer: Coco, Ayudante: Felicito\n");
            if (usa_camioneta2)  printf("- Camioneta 2: Chofer/Ayudante: Garfio\n");
        }
        if (dia_semana == 2 || dia_semana == 4 || dia_semana == 6) {
            if (usa_camion)      printf("- Camion: Chofer: Coco, Ayudante: Felicito\n");
            if (usa_camioneta1)  printf("- Camioneta 1: Chofer: Pedro, Ayudante: Romualdo\n");
            if (usa_camioneta2)  printf("- Camioneta 2: Chofer/Ayudante: Garfio\n");
        }
    }

    printf("\nCostos:\n");
    printf("- Transporte: $%d\n", costo_transporte);
    printf("- Choferes: $%d\n", costo_choferes);
    printf("- Ayudantes: $%d\n", costo_ayudantes);
    if (costo_ayudante_extra)
        printf("- Ayudante extra: $%d\n", costo_ayudante_extra);
    printf("- Descuento/Recargo aplicado sobre transporte: %.2f\n", factor_descuento * factor_recargo_dist);
    printf("- Costo total del viaje: $%.2f\n", costo_total);
    printf("==============================\n");

    return 0;
}
