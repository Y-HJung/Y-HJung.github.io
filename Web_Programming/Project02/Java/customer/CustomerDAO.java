package customer;
import java.sql.*;

public class CustomerDAO {
	Connection conn;
	PreparedStatement ps;
	ResultSet rs;
	String url, user, pass;
	public CustomerDAO() {
		try {
			Class.forName("org.postgresql.Driver");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		url="jdbc:postgresql://localhost:5432/hjdb";
		user="hyejung";
		pass="jung0107";
	}
	 
	public int insertCustomer(String id, String passwd, String name, String gender, String tel) throws SQLException {
		String sql = "insert into customer (id, passwd, name, gender, tel) values (?,?,?,?,?);";
		try {
			conn = DriverManager.getConnection(url, user, pass);
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			ps.setString(2, passwd);
			ps.setString(3, name);
			ps.setString(4, gender);
			ps.setString(5, tel);
			int rec_no = ps.executeUpdate();
			return rec_no;
		} finally {
			if(ps != null)
				ps.close();
			if(conn != null)
				conn.close();
		}
	}
	
	public int checkId(String id) throws Exception {
		int check = 0;
		String sql = "select * from customer where id=?;";
		try {
			conn = DriverManager.getConnection(url, user, pass);
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			ResultSet rs = ps.executeQuery();
			if(rs.next()) {
				check = 1;
			}
			else {
				check = 0;
			}
		} finally {
			if(ps!=null)
				ps.close();
			if(conn!=null)
				conn.close();
		}
		return check;
	}
	
	public boolean checkIdPwd(String id, String passwd) throws SQLException {
		boolean flag = false;
		String sql = "select * from customer where id=?";
		try {
			conn = DriverManager.getConnection(url, user, pass);
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			ResultSet rs = ps.executeQuery();
			if(rs.next()) {
				if(id.equals(rs.getString("id").trim())&&passwd.equals(rs.getString("passwd").trim()))
				{
					flag = true;
				} else {
					flag = false;
				}
			}
		} finally {
			if(ps!=null)
				ps.close();
			if(conn!=null)
				conn.close();
		}
		return flag;
	}
	
	public String checkName(String id) throws SQLException {
		String sql = "select name from customer where id=?";
		String name = "";
		try {
			conn = DriverManager.getConnection(url, user, pass);
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			ResultSet rs = ps.executeQuery();
			while(rs.next())
				name = rs.getString(1);
			return name;
		} finally {
			if(ps!=null)
				ps.close();
			if(conn!=null)
				conn.close();
		}
	}
	
	public String getId(String id) throws SQLException {
		String sql = "select id from customer where id=?";
		String ID = "";
		try {
			conn = DriverManager.getConnection(url, user, pass);
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			ResultSet rs = ps.executeQuery();
			while(rs.next())
				ID = rs.getString(1);
			return ID;
		} finally {
			if(ps!=null)
				ps.close();
			if(conn!=null)
				conn.close();
		}
	}
	
	public String checkTel(String id) throws SQLException {
		String sql = "select tel from customer where id=?";
		String tel = "";
		try {
			conn = DriverManager.getConnection(url, user, pass);
			ps = conn.prepareStatement(sql);
			ps.setString(1, id);
			ResultSet rs = ps.executeQuery();
			while(rs.next()) {
				tel = rs.getString(1);
			}
			return tel;
		} finally {
			if(ps!=null)
				ps.close();
			if(conn!=null)
				conn.close();
		}
	}
	
	public int updateInfo(String id, String pw, String name, String tel) throws SQLException {
		String sql = "update customer set passwd=?, name=?, tel=? where id=?;";
		try {
			conn = DriverManager.getConnection(url, user, pass);
			ps = conn.prepareStatement(sql);
			ps.setString(1, pw);
			ps.setString(2, name);
			ps.setString(3, tel);
			ps.setString(4, id);
			int rec_no = ps.executeUpdate();
			return rec_no;
		} finally {
			if(ps!=null)
				ps.close();
			if(conn!=null)
				conn.close();
		}
	}
}

