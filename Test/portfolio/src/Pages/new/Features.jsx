import React from "react";
import {
  Zap, Brain, TimerReset , Award, Smartphone , BookOpenCheck , Trophy,FileBarChart  
} from "lucide-react";

// Utility to merge Tailwind classNames
const cn = (...classes) => classes.filter(Boolean).join(" ");

// Card Components
const Card = React.forwardRef(({ className, ...props }, ref) => (
  <div ref={ref} className={cn("rounded-lg border bg-white text-gray-900 shadow-sm", className)} {...props} />
));
const CardHeader = React.forwardRef(({ className, ...props }, ref) => (
  <div ref={ref} className={cn("flex flex-col space-y-1.5 p-6", className)} {...props} />
));
const CardTitle = React.forwardRef(({ className, ...props }, ref) => (
  <h3 ref={ref} className={cn("text-2xl font-semibold leading-none tracking-tight", className)} {...props} />
));
const CardDescription = React.forwardRef(({ className, ...props }, ref) => (
  <p ref={ref} className={cn("text-sm text-gray-600", className)} {...props} />
));
const CardContent = React.forwardRef(({ className, ...props }, ref) => (
  <div ref={ref} className={cn("p-6 pt-0", className)} {...props} />
));

const Features = () => {
  const features = [
    {
      icon: TimerReset ,
      title: "Instant Results",
      description: "Get your score and detailed performance analysis immediately after finishing a test. See strengths, weaknesses, time spent, and topic-wise breakdown to improve faster.",
      gradientFrom: "from-purple-500",
      gradientTo: "to-indigo-600",
      borderColor: "border-purple-200"
    },
    {
      icon: Trophy ,
      title: "Leaderboards",
      description:"Compete with peers across the country and see where you stand in real-time. Gain motivation by tracking your rank among top performers, filter by region or skill, and climb your way to the top." ,
      gradientFrom: "from-emerald-500",
      gradientTo: "to-teal-600",
      borderColor: "border-emerald-200"
    },
    {
      icon: FileBarChart ,
      title: "Detailed Reports",
      description: "Receive in-depth analytics after every test—identify strong areas, weak topics, time management patterns, and get AI-generated improvement suggestions tailored to your performance history." ,
      gradientFrom: "from-blue-500",
      gradientTo: "to-cyan-600",
      borderColor: "border-blue-200"
    },
    {
      icon: Smartphone ,
      title: "Mobile Friendly",
      description: "Access full test functionality on any device—whether you're using a phone, tablet, or laptop. With a fully responsive interface and offline mode support, you can practice seamlessly, even on the go." ,
      gradientFrom: "from-orange-500",
      gradientTo: "to-red-600",
      borderColor: "border-orange-200"
    },
    {
      icon: BookOpenCheck ,
      title: "Subject-wise Practice",
      description:"Master each subject at your own pace by selecting focused practice sets from Math, Science, English, and more. Get chapter-level questions, smart difficulty adaptation, and instant feedback tailored to each topic.",
      gradientFrom: "from-indigo-500",
      gradientTo: "to-purple-600",
      borderColor: "border-indigo-200"
    },
  ];

  return (
    <section className="py-32 bg-gradient-to-b from-slate-50 via-white to-slate-50 relative overflow-hidden">
      {/* Grid background */}
      <div className="absolute inset-0 bg-[linear-gradient(to_right,#8080800a_1px,transparent_1px),linear-gradient(to_bottom,#8080800a_1px,transparent_1px)] bg-[size:20px_20px]"></div>

      <div className="relative max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        {/* Header */}
        <div className="text-center mb-24">
          <div className="inline-flex items-center space-x-3 bg-gradient-to-r from-purple-600 to-blue-600 text-white rounded-full px-6 py-3 text-sm font-medium mb-6 shadow-lg">
            <Zap className="h-5 w-5 animate-pulse" />
            <span>Revolutionary Technology Stack</span>
            <Brain className="h-5 w-5" />
          </div>
          <h2 className="text-5xl md:text-7xl font-bold text-gray-900 mb-8 leading-tight">
            Beyond Traditional
            <span className="block bg-gradient-to-r from-purple-600 via-blue-600 to-cyan-600 bg-clip-text text-transparent">
              Assessment Platforms
            </span>
          </h2>
          <p className="text-2xl text-gray-600 max-w-4xl mx-auto leading-relaxed">
            Powered by innovation and engineered for the future workplace. 
            Experience assessment technology that outpaces traditional platforms.
          </p>
        </div>

        {/* Feature Cards */}
        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-10">
          {features.map((feature, index) => {
            const Icon = feature.icon;
            return (
              <Card
                key={index}
                className={`group relative overflow-hidden hover:shadow-3xl transition-all duration-700 hover:-translate-y-4 border-2 ${feature.borderColor} hover:border-opacity-0 bg-white/80 backdrop-blur-sm`}
              >
                {/* Hover BG */}
                <div className={`absolute inset-0 bg-gradient-to-br ${feature.gradientFrom} ${feature.gradientTo} opacity-0 group-hover:opacity-10 transition-opacity duration-700`} />
                <div className={`absolute -top-6 -right-6 w-24 h-24 bg-gradient-to-br ${feature.gradientFrom} ${feature.gradientTo} rounded-full opacity-10 group-hover:scale-150 group-hover:opacity-20 transition-all duration-700`} />

                <CardHeader className="relative z-10 pb-6">
                  <div className={`w-20 h-20 rounded-3xl bg-gradient-to-br ${feature.gradientFrom} ${feature.gradientTo} flex items-center justify-center mb-6 group-hover:scale-110 group-hover:rotate-6 transition-all duration-500 shadow-2xl`}>
                    <Icon className="h-10 w-10 text-white" />
                  </div>
                  <CardTitle className="text-2xl font-bold text-gray-900 group-hover:text-gray-800 mb-4">
                    {feature.title}
                  </CardTitle>
                </CardHeader>

                <CardContent className="relative z-10">
                  <CardDescription className="text-gray-600 text-lg leading-relaxed group-hover:text-gray-700">
                    {feature.description}
                  </CardDescription>
                </CardContent>

                <div className={`absolute bottom-0 left-0 right-0 h-2 bg-gradient-to-r ${feature.gradientFrom} ${feature.gradientTo} transform scale-x-0 group-hover:scale-x-100 transition-transform duration-700 origin-left`} />
                <div className={`absolute top-4 right-4 w-3 h-3 bg-gradient-to-r ${feature.gradientFrom} ${feature.gradientTo} rounded-full opacity-0 group-hover:opacity-100 transition-opacity duration-500`} />
              </Card>
            );
          })}
        </div>

        {/* Trust Section */}
        {/* <div className="mt-32 text-center">
          <div className="bg-gradient-to-r from-gray-900 via-purple-900 to-gray-900 rounded-3xl p-12 text-white relative overflow-hidden">
            <div className="absolute inset-0 bg-[linear-gradient(to_right,#ffffff0a_1px,transparent_1px),linear-gradient(to_bottom,#ffffff0a_1px,transparent_1px)] bg-[size:20px_20px]" />

            <div className="relative z-10">
              <div className="flex justify-center mb-6">
                <div className="w-16 h-16 bg-gradient-to-r from-yellow-400 to-orange-500 rounded-2xl flex items-center justify-center shadow-2xl">
                  <Award className="h-8 w-8 text-white" />
                </div>
              </div>
              <h3 className="text-3xl font-bold mb-6">Trusted by Global Leaders</h3>
              <p className="text-xl text-gray-300 mb-10 max-w-3xl mx-auto">
                Our platform powers assessment systems for Fortune 500 companies, leading universities, and government organizations worldwide.
              </p>
              <div className="grid grid-cols-2 md:grid-cols-5 gap-8 items-center opacity-70">
                <div className="text-2xl font-bold text-gray-300">Microsoft</div>
                <div className="text-2xl font-bold text-gray-300">Google</div>
                <div className="text-2xl font-bold text-gray-300">Amazon</div>
                <div className="text-2xl font-bold text-gray-300">Meta</div>
                <div className="text-2xl font-bold text-gray-300">Apple</div>
              </div>
            </div>
          </div>
        </div> */}
        
      </div>
    </section>
  );
};

export default Features;



