<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<jsp:useBean id="dto" class="customer.CustomerDTO" scope="session"/>
<jsp:setProperty property="passwd" name="dto"/>
<jsp:setProperty property="name" name="dto"/>
<jsp:setProperty property="tel" name="dto"/>
<jsp:useBean id="dao" class="customer.CustomerDAO"/>
<title>회원정보 수정</title>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
</head>
<body>
<%
int rec_no = dao.updateInfo(dto.getId(), dto.getPasswd(), dto.getName(), dto.getTel());
if (rec_no > 0) {
%>
<script>alert("수정이 완료되었습니다."); location.href="./loginSuc_main.jsp";</script>
<%
}
%>
</body>
</html>
