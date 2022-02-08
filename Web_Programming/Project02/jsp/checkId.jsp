<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<jsp:useBean id="dao" class="customer.CustomerDAO"/>
<%
String id = request.getParameter("id");
int check = 0;
String ans = "";
if(id == null) {
	id = "";
}
if(!id.equals("")){
	check = dao.checkId(id);
}
if(check==1) {
	ans = "NO";
	out.print(ans);
	System.out.println(ans);  // 값 넘어가는거 확인용
} else {
	ans = "YES";
	out.print(ans);
	System.out.println(ans);
}
%>
