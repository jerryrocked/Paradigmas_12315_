
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.ResultSet;
import com.mysql.jdbc.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.HashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumn;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */

/**
 *
 * @author benja
 */
public class consultaVentas extends javax.swing.JFrame {
    
    Connection con = null;
    Statement stmt = null;
    String titulos[] = {"id","Nombre","Ventas CoD","Ventas Mine","Ventas Fort","Ventas totales","Comision CoD", "Comision Mine", "Comision Fort", "Comision total"};
    String fila[] = new String [10];
    DefaultTableModel modelo;

    public consultaVentas() {
        initComponents();
        this.setTitle("Consulta Ventas");
        this.setLocation(335,200);
        this.setResizable(true);
        ImageIcon icono = new ImageIcon("C:\\Users\\benja\\OneDrive\\Documentos\\NetBeansProjects\\tarea2\\src\\images\\fortnite.jpg");
        this.setIconImage(icono.getImage());
        
        
        
        try {
            
            String url = "jdbc:mysql://localhost:3306/tarea2?characterEncoding=utf8";
            String usuario = "root";
            String contraseña = "admin";
            
               Class.forName("com.mysql.jdbc.Driver").newInstance();
               con = (Connection) DriverManager.getConnection(url,usuario,contraseña);
               if (con!= null)
                   System.out.println("Se ha establecido una conexion a la base de datos"+"\n"+url);
               
               stmt = (Statement) con.createStatement();
               ResultSet rs = (ResultSet) stmt.executeQuery("select * from usuarios");
               
               modelo = new DefaultTableModel(null,titulos);
               
               //int i = 1;
               int mayor = 0;
               String nom_alt = "No hay registros";
               while(rs.next()) {
                   
                   fila[0] = rs.getString("id");
                   fila[1] = rs.getString("nombre");
                   fila[2] = rs.getString("cod");
                   fila[3] = rs.getString("mine");
                   fila[4] = rs.getString("fort");
                   fila[5] = rs.getString("tot_vent");
                   fila[6] = rs.getString("com_cod");
                   fila[7] = rs.getString("com_mine");
                   fila[8] = rs.getString("com_fort");
                   fila[9] = rs.getString("com_tot");
                   modelo.addRow(fila);
                   
                   if(Integer.valueOf(fila[9]) > mayor ){
                       mayor = Integer.valueOf(fila[9]);
                       nom_alt = fila[1];
                   }
               }
               com_m_alt.setText(Integer.toString(mayor));
               nom_com_alt.setText(nom_alt);
               
               tabla_sellers.setModel(modelo);
               
                TableColumn ci = tabla_sellers.getColumn("id");
                ci.setMaxWidth(25);
                
            

               
        }
        catch (Exception e) {
            
            JOptionPane.showMessageDialog(null,"Presione Ok");
        }
    }


    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        tabla_sellers = new javax.swing.JTable();
        jLabel1 = new javax.swing.JLabel();
        com_m_alt = new javax.swing.JTextField();
        nom_com_alt = new javax.swing.JTextField();
        id_dlt = new javax.swing.JTextField();
        btn_dlt = new javax.swing.JButton();
        barra_menu = new javax.swing.JMenuBar();
        menu_arch = new javax.swing.JMenu();
        menu_reg = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        tabla_sellers.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));
        jScrollPane1.setViewportView(tabla_sellers);

        jLabel1.setFont(new java.awt.Font("Times New Roman", 0, 24)); // NOI18N
        jLabel1.setText("Comisión más alta:");

        com_m_alt.setEditable(false);
        com_m_alt.setFont(new java.awt.Font("Times New Roman", 0, 24)); // NOI18N
        com_m_alt.setFocusable(false);
        com_m_alt.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                com_m_altKeyTyped(evt);
            }
        });

        nom_com_alt.setEditable(false);
        nom_com_alt.setFont(new java.awt.Font("Times New Roman", 0, 24)); // NOI18N
        nom_com_alt.setFocusable(false);
        nom_com_alt.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                nom_com_altKeyTyped(evt);
            }
        });

        id_dlt.setFont(new java.awt.Font("Times New Roman", 0, 18)); // NOI18N
        id_dlt.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyTyped(java.awt.event.KeyEvent evt) {
                id_dltKeyTyped(evt);
            }
        });

        btn_dlt.setFont(new java.awt.Font("Times New Roman", 0, 18)); // NOI18N
        btn_dlt.setText("Eliminar por ID:");
        btn_dlt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_dltActionPerformed(evt);
            }
        });

        menu_arch.setText("Archivo");

        menu_reg.setText("Registro");
        menu_reg.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                menu_regActionPerformed(evt);
            }
        });
        menu_arch.add(menu_reg);

        barra_menu.add(menu_arch);

        setJMenuBar(barra_menu);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 906, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addGap(37, 37, 37)
                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 193, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(35, 35, 35)
                .addComponent(nom_com_alt, javax.swing.GroupLayout.PREFERRED_SIZE, 254, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(58, 58, 58)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(btn_dlt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGap(18, 18, 18)
                        .addComponent(id_dlt, javax.swing.GroupLayout.PREFERRED_SIZE, 52, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(com_m_alt, javax.swing.GroupLayout.PREFERRED_SIZE, 234, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(nom_com_alt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(com_m_alt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 45, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btn_dlt)
                    .addComponent(id_dlt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(33, 33, 33))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    public void eliminar() {
    
    if (id_dlt.getText().equals("")) {
         javax.swing.JOptionPane.showMessageDialog(this,"Escriba una ID válida","AVISO!",javax.swing.JOptionPane.INFORMATION_MESSAGE);
     }
     else {
     try { 
                  String url = "jdbc:mysql://localhost:3306/tarea2?characterEncoding=utf8"; 
                  String usuario = "root"; 
                  String contraseña = "admin"; 
                  
                  Class.forName("com.mysql.jdbc.Driver").newInstance(); 
                  con = (Connection) DriverManager.getConnection(url,usuario,contraseña); 
                  if ( con != null ) 
                    System.out.println("Se ha establecido una conexión a la base de datos " +  
                                       "\n " + url ); 
  
                  stmt = (Statement) con.createStatement(); 
                  stmt.executeUpdate("delete from usuarios where id= '"+id_dlt.getText()+"'"); 

                  System.out.println("Usuario Eliminado"); 
                  } 
                  catch( SQLException e ) { 
                      e.printStackTrace(); 
                  } catch (ClassNotFoundException ex) { 
            Logger.getLogger(usuarios.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            Logger.getLogger(usuarios.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            Logger.getLogger(usuarios.class.getName()).log(Level.SEVERE, null, ex);
        } 
  
              finally { 
                  if ( con != null ) { 
                      try    { 
                          con.close(); 
                          stmt.close(); 
                      } catch( Exception e ) { 
                          System.out.println( e.getMessage()); 
                      } 
                  } 
     }
     javax.swing.JOptionPane.showMessageDialog(this,"Usuario Eliminado!","AVISO!",javax.swing.JOptionPane.INFORMATION_MESSAGE);
     } 
    this.dispose();
    consultaVentas cv =  new consultaVentas();
    cv.setVisible(true);
    }
    
    private void menu_regActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_menu_regActionPerformed
        // TODO add your handling code here:
        this.dispose();
        usuarios u =  new usuarios();
        u.setVisible(true);
    }//GEN-LAST:event_menu_regActionPerformed

    private void nom_com_altKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_nom_com_altKeyTyped
        // TODO add your handling code here:
        char c = evt.getKeyChar();
        if((c<'a')||(c>'z') && (c<'A')||(c>'Z')){
            evt.consume();
        }
    }//GEN-LAST:event_nom_com_altKeyTyped

    private void com_m_altKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_com_m_altKeyTyped
        // TODO add your handling code here:
        char c = evt.getKeyChar();
        if((c<0)||(c>9)){
            evt.consume();
        }
    }//GEN-LAST:event_com_m_altKeyTyped

    private void id_dltKeyTyped(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_id_dltKeyTyped
        // TODO add your handling code here:
        char c = evt.getKeyChar();
        if(c<'0' || c>'9') evt.consume();
    }//GEN-LAST:event_id_dltKeyTyped

    private void btn_dltActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_dltActionPerformed
        // TODO add your handling code here:
        eliminar();
    }//GEN-LAST:event_btn_dltActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(consultaVentas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(consultaVentas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(consultaVentas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(consultaVentas.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new consultaVentas().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuBar barra_menu;
    private javax.swing.JButton btn_dlt;
    private javax.swing.JTextField com_m_alt;
    private javax.swing.JTextField id_dlt;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JMenu menu_arch;
    private javax.swing.JMenuItem menu_reg;
    private javax.swing.JTextField nom_com_alt;
    private javax.swing.JTable tabla_sellers;
    // End of variables declaration//GEN-END:variables
}
