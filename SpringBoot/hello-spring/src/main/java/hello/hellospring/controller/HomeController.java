package hello.hellospring.controller;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
@Controller
public class HomeController {
    @GetMapping("/") //첫번째 도메인
    public String home() {
        return "home"; //home.html로 연결
    }
}