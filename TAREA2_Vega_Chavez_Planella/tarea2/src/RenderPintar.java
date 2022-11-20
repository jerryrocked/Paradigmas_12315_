
import java.awt.Color;
import java.awt.Component;
import javax.swing.JTable;
import javax.swing.JLabel;
import javax.swing.table.DefaultTableCellRenderer;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author benja
 */
public class RenderPintar extends DefaultTableCellRenderer{

    @Override
    public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
        JLabel labelResultado = (JLabel)super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
        
        if(value instanceof String){
            String Dato = (String)value;
            
            if(Dato.equals("Jose")){
                labelResultado.setBackground(Color.blue);
                labelResultado.setForeground(Color.white);
            }
        }
        
        
        return labelResultado;
    }
     
    
}
