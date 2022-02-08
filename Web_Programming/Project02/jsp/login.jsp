<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<% request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<title>로그인</title>
<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<jsp:useBean id="dto" class="customer.CustomerDTO" scope="session"/>
<jsp:setProperty property="id" name="dto"/>
<jsp:useBean id="dao" class="customer.CustomerDAO" scope="session"/>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>
<body>
<%
String login_id = request.getParameter("id");
String login_passwd = request.getParameter("passwd");
if(dao.checkIdPwd(login_id, login_passwd))
{
	dto.setId(login_id);
	dto.setVerified(true);
	response.sendRedirect("./loginSuc_main.jsp");
} else {
%>
<script>alert("아이디나 비밀번호가 잘못 입력 되었습니다.\n아이디와 비밀번호를 정확히 입력해 주세요."); location.href="../login.html";</script>
<%
	}
%>
</body>
</html>
