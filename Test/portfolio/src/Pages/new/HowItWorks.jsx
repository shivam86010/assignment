
import * as React from "react";
import { UserPlus, BookOpen, Award, Briefcase } from "lucide-react";

// Utility function
function cn(...classes) {
  return classes.filter(Boolean).join(" ");
}

// Card Component
const Card = React.forwardRef(({ className, ...props }, ref) => (
  <div
    ref={ref}
    className={cn("rounded-lg border bg-white text-gray-900 shadow-sm", className)}
    {...props}
  />
));
Card.displayName = "Card";

// CardContent Component
const CardContent = React.forwardRef(({ className, ...props }, ref) => (
  <div ref={ref} className={cn("p-6 pt-0", className)} {...props} />
));
CardContent.displayName = "CardContent";

// Main Component
const HowItWorks = () => {
  const steps = [
    {
      icon: UserPlus,
      title: "Sign Up",
      description: "Create your free account and complete your profile to get started.",
      step: "01"
    },
    {
      icon: BookOpen,
      title: "Practice & Test",
      description: "Take practice tests to prepare, then attempt official assessments.",
      step: "02"
    },
    {
      icon: Award,
      title: "Get Certified",
      description: "Receive instant certificates based on your test performance.",
      step: "03"
    },
    {
      icon: Briefcase,
      title: "Connect with Employers",
      description: "Share your certificates and get noticed by top companies.",
      step: "04"
    }
  ];

  return (
    <section className="py-20 bg-white">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div className="text-center mb-16">
          <h2 className="text-3xl md:text-5xl font-bold text-gray-900 mb-4">
            How It Works
          </h2>
          <p className="text-xl text-gray-600 max-w-3xl mx-auto">
            Get started with our simple 4-step process to advance your career.
          </p>
        </div>

     <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-8">
  {steps.map((step, index) => (
    <div key={index} className="relative h-full">
      <Card className="group hover:shadow-lg transition-all duration-300 hover:-translate-y-1 h-full flex flex-col justify-between">
        <CardContent className="p-6 text-center flex flex-col flex-grow">
          <div className="relative mb-6">
            <div className="w-16 h-16 bg-blue-100 rounded-full flex items-center justify-center mx-auto mb-4 group-hover:bg-blue-200 transition-colors">
              <step.icon className="h-8 w-8 text-blue-600" />
            </div>
            <span className="absolute -top-2 -right-2 w-8 h-8 bg-blue-600 text-white text-sm font-bold rounded-full flex items-center justify-center">
              {step.step}
            </span>
          </div>
          <h3 className="text-xl font-semibold text-gray-900 mb-3">
            {step.title}
          </h3>
          <p className="text-gray-600 flex-grow">
            {step.description}
          </p>
        </CardContent>
      </Card>

      {/* Connector Line */}
      {index < steps.length - 1 && (
        <div className="hidden lg:block absolute top-1/2 -right-4 w-8 h-0.5 bg-blue-200 transform -translate-y-1/2"></div>
      )}
    </div>
  ))}
</div>

      </div>
    </section>
  );
};

export default HowItWorks;


