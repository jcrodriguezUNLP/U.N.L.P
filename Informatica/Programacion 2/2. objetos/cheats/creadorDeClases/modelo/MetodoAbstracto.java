package modelo;

import java.util.ArrayList;
import java.util.List;

public class MetodoAbstracto extends Elemento {
    private static final long serialVersionUID = 1L;
    private List<Variable> parametros;

    public MetodoAbstracto(String tipo, String nombre) {
        super(tipo, nombre);
        this.parametros = new ArrayList<>();
    }

    public List<Variable> getParametros() {
        if (parametros == null) {
            parametros = new ArrayList<>();
        }
        return parametros;
    }

    public void setParametros(List<Variable> parametros) {
        this.parametros = parametros;
    }

    @Override
    public String generarCodigo() {
        StringBuilder sb = new StringBuilder();
        sb.append("public ").append(tipo).append(" ").append(nombre).append("( ");
        List<Variable> params = getParametros();
        for (int i = 0; i < params.size(); i++) {
            Variable p = params.get(i);
            sb.append(p.getTipo()).append(" ").append(p.getNombre());
            if (i < params.size() - 1) sb.append(" , ");
        }
        sb.append(" )");
        return sb.toString();
    }
}
