# importamos herramientas que se uilizaran en el programa
import numpy             as np
import matplotlib.pyplot as plt

from scipy.optimize import curve_fit
from scipy.optimize import minimize


# Datos experimentales

# Cargar los valores de estiramiento y sus incertidumbres dentro del corchete y separado por coma
estiramiento       = np.array([ 0.3  , 0.5  , 0.7  , 0.9  , 1.2  ]) / 100  # Estiramiento en m
error_estiramiento = np.array([ 0.05 , 0.05 , 0.05 , 0.05 , 0.05 ]) / 100  # Error en el estiramiento en m


# Cargar los valores de fuerza y sus incertidumbres dentro del corchete y separado por coma
fuerza       = np.array([ 0.1   , 0.2   , 0.3   , 0.4   , 0.5   ])      # Fuerza en Newton
error_fuerza = np.array([ 0.05 , 0.05 , 0.05 , 0.05 , 0.05 ])      # Error en la fuerza 
 

# Cargar los valores de masa y sus incertidumbres en gramos, ya que en la misma linea
# se divide por mil para pasar a kilos y se multiplica por g = 9.8
# para pasarlo a peso en newton
peso       = np.array([ 0.10 , 0.20 , 0.30 , 0.40 , 0.50 ])/1000*9.8      # Peso en Newton
error_peso = np.array([ 0.01 , 0.01 , 0.01 , 0.01 , 0.01 ])/1000*9.8      # Error en el peso


# Graficar los datos experimentales, fuerza vs estiramiento
# Creamos el gráfico, como es un grafico de datos con errores usamos plt.errorbar
plt.errorbar(estiramiento, fuerza, xerr=error_estiramiento, yerr=error_fuerza, fmt='o', capsize=5)

# Etiquetas de los ejes
plt.xlabel('Estiramiento (m)')
plt.ylabel('Fuerza (N)')

# Título del gráfico
plt.title('Fuerza vs estiramiento')

# Mostrar el gráfico
plt.show()

# Graficar los datos experimentales, peso vs estiramiento
# Creamos el gráfico, como es un grafico de datos con errores usamos plt.errorbar
plt.errorbar(estiramiento, peso, xerr=error_estiramiento, yerr=error_peso, fmt='o', capsize=5)

# Etiquetas de los ejes
plt.xlabel('Estiramiento (m)')
plt.ylabel('Peso (N)')

# Título del gráfico
plt.title('Peso vs estiramiento')

# Mostrar el gráfico
plt.show()

#Funcion que determina la pendiente y su incertidumbre de una recta sin ordenada
def york_fit_no_intercept(x, y, err_x, err_y, max_iter=100, tol=1e-10):
    # Inicialización de valores
    m = np.sum(x * y / (err_x**2 + err_y**2)) / np.sum(x**2 / (err_x**2 + err_y**2))

    for _ in range(max_iter):
        w = 1 / (err_y**2 + m**2 * err_x**2)
        m_new = np.sum(w * x * y) / np.sum(w * x**2)

        if abs(m_new - m) < tol:
            m = m_new
            break
        m = m_new

    # Cálculo de la incertidumbre en la pendiente
    sigma_m = np.sqrt(1 / np.sum(w * x**2))

    return m, sigma_m

#Funcion que permite escribir la pendiente y la incertidumbre con el numero de cifras significativas deseado
def format_with_uncertainty(value, uncertainty, sig_figs=2):
    if uncertainty == 0:
        return f"{value:.{sig_figs}g}"
    # Obtener el orden de magnitud de la incertidumbre
    uncertainty_order = np.floor(np.log10(abs(uncertainty)))
    # Redondear la incertidumbre al número deseado de cifras significativas
    uncertainty_rounded = round(uncertainty, sig_figs - 1 - int(uncertainty_order))
    # Redondear el valor en función de la incertidumbre
    value_rounded = round(value, sig_figs - 1 - int(uncertainty_order))
    # Formatear el valor y la incertidumbre en notación de punto fijo
    format_str = f"{{:.{sig_figs - 1 - int(uncertainty_order)}f}}"
    formatted_value = format_str.format(value_rounded)
    formatted_uncertainty = format_str.format(uncertainty_rounded)
    # Verificar si el valor formateado termina en '.0' o en '.00', etc.
    if formatted_value.endswith('.' + '0' * (sig_figs - 1 - int(uncertainty_order))):
        formatted_value = f"{value_rounded:.{sig_figs - 1 - int(uncertainty_order)}f}"
    # Eliminar ceros innecesarios del final de la incertidumbre
    formatted_uncertainty = formatted_uncertainty.rstrip('0').rstrip('.')

    return formatted_value, formatted_uncertainty

# Aplicar el método de ajuste de recta sin ordenada al origen a Fuerza vs estiramiento
pendiente_F, error_pendiente_F = york_fit_no_intercept(estiramiento, fuerza, error_estiramiento, error_fuerza)
k_F, error_k_F = format_with_uncertainty(pendiente_F, error_pendiente_F, sig_figs=1)

print('Fuerza vs estiramiento:')
print(f"   Pendiente k: {k_F} N/m")
print(f"   Incertidumbre en la pendiente Δk: {error_k_F} N/m")

# Aplicar el método de ajuste de recta sin ordenada al origen a Fuerza vs estiramiento
pendiente_P, error_pendiente_P = york_fit_no_intercept(estiramiento, peso, error_estiramiento, error_peso)
k_P, error_k_P = format_with_uncertainty(pendiente_P, error_pendiente_P, sig_figs=1)

print('Peso vs estiramiento:')
print(f"   Pendiente k: {k_P} N/m")
print(f"   Incertidumbre en la pendiente Δk: {error_k_P} N/m")

# Creamos un gráfico con los datos y la recta ajustada para la fuerza:
plt.ylabel('Fuerza (N)')
plt.xlabel('Estiramiento (m)')

# Título del gráfico
plt.title('Fuerza vs estiramiento')

plt.errorbar(estiramiento, fuerza, xerr=error_estiramiento, yerr=error_fuerza, fmt='o', capsize=5)

# Graficar la recta ajustada
x_fit = np.linspace(min(estiramiento), max(estiramiento), 100)
y_fit = x_fit*pendiente_F
y_fitmas = x_fit*(pendiente_F+error_pendiente_F)
y_fitmenos = x_fit*(pendiente_F-error_pendiente_F)

plt.plot(x_fit, y_fit, 'r-', label=f'k = {k_F} N/m')
plt.plot(x_fit, y_fitmas, 'r--', label=f'k = {k_F} + {error_k_F}')
plt.plot(x_fit, y_fitmenos, 'r--', label=f'k = {k_F} - {error_k_F}')

# Mostrar la leyenda
plt.legend()

# Mostrar el gráfico
plt.show()

# Creamos un gráfico con los datos y la recta ajustada para la fuerza:
plt.ylabel('Peso (N)')
plt.xlabel('Estiramiento (m)')

# Título del gráfico
plt.title('Peso vs estiramiento')

plt.errorbar(estiramiento, peso, xerr=error_estiramiento, yerr=error_peso, fmt='o', capsize=5)

# Graficar la recta ajustada
x_fit = np.linspace(min(estiramiento), max(estiramiento), 100)
y_fit = x_fit*pendiente_P
y_fitmas = x_fit*(pendiente_P+error_pendiente_P)
y_fitmenos = x_fit*(pendiente_P-error_pendiente_P)

plt.plot(x_fit, y_fit, 'r-', label=f'k = {k_P} N/m')
plt.plot(x_fit, y_fitmas, 'r--', label=f'k = {k_P} + {error_k_P}')
plt.plot(x_fit, y_fitmenos, 'r--', label=f'k = {k_P} - {error_k_P}')

# Mostrar la leyenda
plt.legend()

# Mostrar el gráfico
plt.show()